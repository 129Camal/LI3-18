package engine;

import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

/**
 * Classe que define um coletivo de Tags.
 * Tem como variaváis de instancia uma hash map cujo o value é o id da tag e o value é a própria tag.
 */
public class CatTags {
    private HashMap<String, Tag> tags;

    /**
     * Construtor por vazio da classe CatTags.
     */
    public CatTags() {
        this.tags = new HashMap<>();
    }

    public Tag getTag(String tag){

        return this.tags.get(tag).clone();

    }

    public void setTag(String tagkey, Tag tag){

        this.tags.put(tagkey,tag);

    }

    public void free() {

        this.tags.clear();
    }

    public int getSize(){

        return this.tags.size();
    }


    public Map<String, Tag> getTags() {
        return this.tags.entrySet().stream().collect(Collectors.toMap(f->f.getKey(), f->f.getValue().clone()));
    }

    public long pickTags(String s){
        return this.tags.get(s).getId();
    }
}
