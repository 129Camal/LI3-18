package engine;

import java.time.LocalDate;
import java.util.Comparator;

/**
 * Classe que define o comparador do número de respostas de dois objetos da classe Question .
 */
public class ComparatorAnswers implements Comparator<Question> {

    public int compare(Question a, Question b){

        int r = a.getnRespostas()-b.getnRespostas();
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}
