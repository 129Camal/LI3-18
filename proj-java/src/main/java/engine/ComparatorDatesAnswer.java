package engine;
import java.time.LocalDate;
import java.util.Comparator;

/**
 * Classe que define o comparador entre a data de dois objectos da classe Answer.
 */
public class ComparatorDatesAnswer implements Comparator<Answer>{

        public int compare(Answer a, Answer b){

            int r = a.getDate().compareTo(b.getDate());
            if (r == 0)
                return 0;
            else if (r < 0)
                return 1;
            else
                return -1;
        }

    }
