package engine;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Classe que define um coletivo de objectos da classe Answers
 * Tem como variavéis um Hashmap de qual a chave é o id duma resposta(Answer) e o value é a resposta(Answer)
 */
public class CatAnswers {
    private HashMap<Long, Answer> answers;

    /**
     * Construtor vazio da classe CatAnswers
     */
    public CatAnswers() {
        this.answers = new HashMap<>();
    }

    public Answer getAnswer(long id){
        Answer a = null;
        if(this.answers.containsKey(id)) {
            return this.answers.get(id).clone();
        }
        return a;
    }

    public void setAnswer(long id, Answer ans){

        this.answers.put(id,ans);

    }

    public void free() {

        this.answers.clear();
    }

    public int getSize(){

        return this.answers.size();
    }

    public boolean contains(long id){

        return this.answers.containsKey(id);
    }

    public Map<Long, Answer> getAnswers() {
        return this.answers.entrySet().stream().collect(Collectors.toMap(f->f.getKey(), f->f.getValue().clone()));
    }
}
