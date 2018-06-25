package engine;

import java.time.LocalDate;
import java.util.Comparator;
import java.util.Map;

/**
 * Classe que define o comparador da data entre dois objetos da classe  Question, inseridos em dois Hashmaps.
 */
public class ComparatorQuestionsEntry implements Comparator<Map.Entry<Long, Question>> {

    public int compare(Map.Entry<Long, Question> a, Map.Entry<Long, Question> b){

        int r = a.getValue().getDate().compareTo(b.getValue().getDate());
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}
