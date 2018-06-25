package engine;


import java.util.Comparator;

/**
 *Classe que define o comparador entre o número total de posts(Perguntas e respostas) entre dois objectos da classe
 * Person.
 */
class ComparatorMostActive implements Comparator<Person>{
	public int compare(Person a, Person b){
		int r = a.getNposts() - b.getNposts();
		if (r == 0)
			return 0;
		else if (r < 0)
			return 1;
		else
			return -1;
	}
} 