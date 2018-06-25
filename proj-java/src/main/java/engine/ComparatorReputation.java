package engine;

import java.util.Comparator;

/**
 * Classe que define o comparador entre a reputação de dois objectos da classe Person.
 */
class ComparatorReputation implements Comparator<Person> {
    public int compare(Person a, Person b){
        long r = a.getReputacao() - b.getReputacao();
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }
}