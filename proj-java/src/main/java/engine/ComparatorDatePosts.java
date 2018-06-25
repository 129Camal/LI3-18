package engine;

import java.time.LocalDate;
import java.util.Comparator;
import java.util.Map;

/**
 * Classe que define o comparador entre a data de dois objectos, inseridos num
 * mapa(sem a data  a chave)
 */
public class ComparatorDatePosts implements Comparator<Map.Entry<LocalDate, Long>> {

    public int compare(Map.Entry<LocalDate, Long> a, Map.Entry<LocalDate, Long> b){

        int r = a.getKey().compareTo(b.getKey());
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }

}
