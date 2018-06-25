
#include "parse.h"

 int parseUser(USERS u, char* path){
 	char* nome = "DisplayName"; 
 	char* aboutme = "AboutMe";
 	char* id = "Id";
 	char* reputation = "Reputation";
 	char* nl = "NULL";
 	xmlChar* i;
 	xmlChar* n;
 	xmlChar* a;
 	xmlChar* r;
 	long numero;
 	PERSON p;
 
 
	xmlDocPtr doc = xmlParseFile(path);
	
 
 	if (doc == NULL) {
 		printf("Document not parsed. \n");
 		return -1;
 	}
 	xmlNodePtr cur = xmlDocGetRootElement(doc);
 	
 	if(!cur){
 		printf("Empty document\n");
 		xmlFreeDoc(doc);
 	} else {
 		
 	for(cur = cur->xmlChildrenNode; cur; cur = cur->next) {	
 				 
 			i = xmlGetProp(cur, (xmlChar *) id);
 			n = xmlGetProp(cur, (xmlChar *) nome);
 			a = xmlGetProp(cur, (xmlChar *) aboutme);
 			r = xmlGetProp(cur, (xmlChar *) reputation);
 			
 			if(i != NULL) {	
 				numero = atol((char*) i);
 				
 				if(numero > 0){
 				int reputacao = atoi((char *)r);
 				
 					if(a==NULL && n==NULL){
 						p = create_person(nl, numero, nl, reputacao, 0); 
 						u = add_user(u, p, numero);
 				
 					}
 					if(n==NULL && a!=NULL){
 						p = create_person(nl, numero, (char*)a, reputacao, 0); 
 						u = add_user(u, p, numero);
 				
 					}
 				
 					if(n!=NULL && a==NULL){
 						p = create_person((char*)n, numero, nl, reputacao, 0); 
 						u = add_user(u, p, numero);
 					}
 					if(n!=NULL && a!=NULL){
 						p = create_person((char*)n, numero, (char*)a, reputacao, 0); 
 						u = add_user(u, p, numero);
 					}
 				}
 			}
 
 			xmlFree(a);
 			xmlFree(n);
 			xmlFree(i);
 			xmlFree(r);	
 		}
 
 	}
 
 	xmlFreeDoc(doc);
 	return 0;
 }



int parsePost(USERS users, QUESTS questions, ANSWERS answers, AVL datesPosts, char* path){
	
	char* titulo = "Title", *postype = "PostTypeId", *id = "Id", *data = "CreationDate";
	char* pai = "ParentId", *nRespostas = "AnswerCount", *dono = "OwnerUserId", *score = "Score";
	char* t = "Tags",  *comentario = "CommentCount";
	char *timestamp, *token;
	xmlChar* title, *ptype, *iden, *date, *nanswer, *father, *pontuacao;
	xmlChar* autor, *ta, *comen;
	int nr_tags = 0;
	NODE p;
	PERSON u;

	int postipo, nrespostas;
	long identificador, f, a;

	xmlDocPtr doc = xmlParseFile(path);

	if (doc == NULL) {
		printf("Document not parsed. \n");
		return -1;
	}
	xmlNodePtr cur = xmlDocGetRootElement(doc);
	if(!cur){
		printf("Empty document\n");
		xmlFreeDoc(doc);
	} else {
		
		cur = cur->xmlChildrenNode;
		while(cur != NULL){
				
			ptype = xmlGetProp(cur, (xmlChar *) postype);
			

			if(ptype){
				postipo = atoi((char*)ptype);
				
				if(postipo < 3 && postipo < 0){
					cur = cur->next;
					continue;
				} 
				
				//ir buscar os atributos	
				iden = xmlGetProp(cur, (xmlChar *) id);
				title = xmlGetProp(cur, (xmlChar *) titulo);
				date = xmlGetProp(cur, (xmlChar *) data);
				father = xmlGetProp(cur, (xmlChar *) pai);
				nanswer = xmlGetProp(cur, (xmlChar *) nRespostas);
				autor = xmlGetProp(cur, (xmlChar *) dono);

				identificador = atol((char*)iden);

				
				
				
				//tranformar a data

				timestamp = (char*)date;
				*(timestamp+10) = '\0';

				token = strtok(timestamp, "-");
				int year = atoi(token);
				
				token = strtok(NULL, "-");
				int month = atoi(token);

				token = strtok(NULL, "-");
				int day = atoi(token);
				

				Date d = createDate(day, month, year);

				//transformar as strings em numeros com o atoi ou atol
				
				
				if(nanswer){
					nrespostas = atoi((char*) nanswer);
				}
				
				
				if(father){
					f = atol((char*)father);
				} 

				a = atol((char*)autor);

				p = get_node(datesPosts, d);
					
				if(p == NULL){
					p = create_node();
					add_node(datesPosts, p, d);
				}
				//Definir as coisas
				if(postipo==1 && a!=-1){
					int numRespostas = atoi((char*)nanswer);
					

					//inserir a pergunta na hash de questoes
					QUESTION q = create_question((char*)title, identificador, a, numRespostas);
					questions = add_question(questions, q, identificador);
					
					//inserir a pergunta na tree ordenada por datas
					p = get_node(datesPosts, d);
					p = set_hashQuestion(p, identificador, a);

						ta = xmlGetProp(cur, (xmlChar *) t);
						char* tags = (char*)ta;

						char** parsed_tags = (char**) malloc(5 * sizeof(char *));

						token = strtok(tags, "><");
   					
   						nr_tags = 0;
  						while(token != NULL){		
      						parsed_tags[nr_tags] = token;
    						token = strtok(NULL, "><");
    						nr_tags++;
      					}

      					if(nr_tags != 0){
							set_tagQ(q, nr_tags, parsed_tags);
						} else {
							set_tagQ(q, 0, NULL);
						}	
						free(parsed_tags);
				}

				if(postipo==2 && a!=-1){

					pontuacao = xmlGetProp(cur, (xmlChar *) score);
					comen = xmlGetProp(cur, (xmlChar *) comentario);
					
					int votes = atoi((char*)pontuacao);
					int comments = atoi((char*)comen);
					xmlFree(pontuacao);
					xmlFree(comen);

					//Inserir resposta na Hash Respostas
					ANSWER res = create_answer(f, identificador, a, votes);
					add_answer(answers, res, identificador);
		
					//Inserir pontuação da resposta
					u = get_user(users, a);
					
					int reputation = get_reputacao(u);
										
					float result = votes * 0.65 + reputation * 0.25 + comments * 0.1;
					
					QUESTION quest = get_question(questions, f);
					
					if(quest!=NULL){
						float aux = get_pontuacaoBestA(quest);

						if(result >= aux){
						set_bestAnswer(quest, identificador);
						set_pontuacaoBestA(quest, result);
						}
					}

					//Inserir respostas na Tree ordenada por datas
					p = get_node(datesPosts, d);
					p = set_hashAnswers(p, identificador, a);
				}

				increment_nposts(users, a);
				
				//dar os frees
				xmlFree(date);
				xmlFree(father);
				xmlFree(nanswer);
				xmlFree(autor);
				xmlFree(iden);
				xmlFree(title);


			}

			xmlFree(ptype);
			cur = cur->next;	
				
		}
	}
	xmlFreeDoc(doc);
	return 0;
}

int parseTags(TAGS tags, char* path){
	
	char* nome = "TagName"; 
	char* id = "Id";
	xmlChar* i;
	xmlChar* n;


	xmlDocPtr doc = xmlParseFile(path);

	if (doc == NULL) {
		printf("Document not parsed. \n");
		return -1;
	}
	xmlNodePtr cur = xmlDocGetRootElement(doc);
	
	if(!cur){
		printf("Empty document\n");
		xmlFreeDoc(doc);
	} else {
		
	for(cur = cur->xmlChildrenNode; cur; cur = cur->next) {	
				
			i = xmlGetProp(cur, (xmlChar *) id);
			n = xmlGetProp(cur, (xmlChar *) nome);
		
			
			if(n != NULL) {
					
				long numero = atol((char*) i);
				char* tag = strdup((char*)n);
				TAG t = create_tag(numero, tag);

				tags = add_tag(tags, t, tag);
			}

	
			xmlFree(n);
			xmlFree(i);	
		}

	}

	xmlFreeDoc(doc);
	return 0;
}