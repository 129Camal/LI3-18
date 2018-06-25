#include "interface.h"
#include "time.h"

int main(int argc, char** argv){
  clock_t tpf = 0;
  
  TAD_community com = init();

  com = load(com, argv[1]);
  
  //info_from_post(com, 801049); 
  //top_most_active(com, 10);
  //get_user_info(com, 15811);
  Date inicio = createDate(1, 8, 2014);
  Date fim = createDate(11, 8, 2014);
  //total_posts(com, inicio, fim);
  //most_voted_answers(com, 5, inicio, fim);
  most_answered_questions(com, 5, inicio, fim);
  //char* s = "nautilus";
  //questions_with_tag(com, s, inicio, fim);
  //contains_word(com, "glib", 10);
  //both_participated(com, 87, 5691, 10); //erros de repetidos no segundo
  //better_answer(com, 5942);
  //most_used_best_rep(com, 10, inicio, fim);

  free_date(inicio);
  free_date(fim);

  clean(com);
  tpf =clock() -tpf;
  printf("Demorou %f segundos a ler\n\n",((float)tpf)/CLOCKS_PER_SEC);

  return 0;

} 

