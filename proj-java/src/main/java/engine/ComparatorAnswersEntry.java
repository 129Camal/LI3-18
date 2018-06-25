package engine;

import java.time.LocalDate;
import java.util.Comparator;
import java.util.Map;

/**
 *Classe que define o comparador entre as datas de dois objetos da classe Answer, ambos inseridos em mapas.
 */
public class ComparatorAnswersEntry implements Comparator<Map.Entry<Long, Answer>> {

    public int compare(Map.Entry<Long, Answer> a, Map.Entry<Long, Answer> b){

        int r = a.getValue().getDate().compareTo(b.getValue().getDate());
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}
