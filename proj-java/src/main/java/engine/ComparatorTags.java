package engine;

import java.util.Comparator;

/**
 * Comparador do número de vezes que uma tag foi usada entre dois objectos da classe Tag.
 */
public class ComparatorTags implements Comparator<Tag> {

    public int compare(Tag a, Tag b){

        int r = a.getContador()-b.getContador();
        if (r == 0)
            return 0;
        else if (r < 0)
            return 1;
        else
            return -1;
    }
}
