package engine;

import java.time.LocalDate;
import java.util.Comparator;

/**
 *Classe que define o comparador do número total de votos entre dois objectos da classe Answer.
 */
public class ComparatorVotes implements Comparator<Answer> {

    public int compare(Answer a, Answer b){

        int r = a.getVotes()-b.getVotes();
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}
