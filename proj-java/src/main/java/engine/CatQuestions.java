package engine;
import java.util.*;
import java.util.stream.Collectors;

/**
 * Classe que define um coletivo de perguntas(Questions).
 * para tal, tem como variavéis de instáncia  um HashMap, cuja a chave é o id da pergunta e o value é a pergunta em si.
 */
public class CatQuestions {
    private HashMap<Long, Question> questions;

    /**
     * Construtor por vazio da classe CatQuestion.
     */
    public CatQuestions() {
        this.questions = new HashMap<>();
    }

    public Question getQuestion(long id){
        Question question = null;
        if(this.questions.containsKey(id)) {
            question = this.questions.get(id).clone();
        }
        return question;
    }

    public void setQuestions(long id, Question ques){

        this.questions.put(id,ques);

    }

    public void free() {

        this.questions.clear();
    }

    public int getSize(){

        return this.questions.size();
    }

    public boolean contains(long id){

        return this.questions.containsKey(id);
    }

    public Map<Long, Question> getQuestions() {
        return this.questions.entrySet().stream().collect(Collectors.toMap(f->f.getKey(), f->f.getValue().clone()));
    }

    public long getBetterAnswer(long id){

        return this.questions.get(id).getBestAnswer();
    }

    public void setBetterAnswer(long id, long value){

        this.questions.get(id).setBestAnswer(value);

    }

    public void setPontuacaoBestA(long id, float a){

        this.questions.get(id).setPontuacaoBestA(a);
    }
}


