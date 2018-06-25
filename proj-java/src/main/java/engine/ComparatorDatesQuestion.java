package engine;



import java.time.LocalDate;
import java.util.Comparator;

/**
 * Classe que define o comparador da data de dois objectos  da classe Question.
 */
class ComparatorDatesQuestion implements Comparator<Question>{
    public int compare(Question a, Question b){

        int r = a.getDate().compareTo(b.getDate());
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}