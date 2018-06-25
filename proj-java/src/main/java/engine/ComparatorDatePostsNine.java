package engine;

import java.time.LocalDate;
import java.util.Comparator;
import java.util.Map;

/**
 * Classe que define o comparador entre data de dois objetos inseridos em mapas(sendo a data o value).
 */
public class ComparatorDatePostsNine implements Comparator<Map.Entry<Long, LocalDate>> {

    public int compare(Map.Entry<Long,LocalDate> a, Map.Entry<Long, LocalDate> b){

        int r = a.getValue().compareTo(b.getValue());
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}

