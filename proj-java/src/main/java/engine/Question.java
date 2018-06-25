package engine;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Objects;

/**
 * Classe que define uma pergunta(Question).
 * Tem como variavéis de instáncia : o id da pergunta, a data em que foi criada, o titulo da pergunta, o número de respostas
 * a pergunta, o id do autor da pergunta, , o id da melhor resposta a pergunta, a pontuação da melhor resposta e a lista das tags
 * que existem na pergunta.
 */

public class Question {
    private long id;
    private LocalDate date;
    private String titulo;
    private int nRespostas;
    private long autor;
    private long bestAnswer;
    private float pontuacaoBestA;
    private ArrayList<String> tags;

    /**
     *Construtor por copia da classe Question
     * @param a - Um objecto da classe Question de qual se vai criar uam copia.
     */

    public Question(Question a){
        this.id=a.getId();
        this.date=a.getDate();
        this.titulo=a.getTitulo();
        this.nRespostas=a.getnRespostas();
        this.autor=a.getAutor();
        this.bestAnswer=a.getBestAnswer();
        this.pontuacaoBestA=a.getPontuacaoBestA();
        this.tags=a.getTags();

    }

    /**
     * Construtor parametrizado da classe Question
     * @param id -Id da pergunta
     * @param date -Data em que foi criada a pergunta
     * @param titulo -Titulo da pergunta
     * @param nRespostas -Número total de respostas a pergunta
     * @param autor - Id do Autor da pergunta
     * @param bestAnswer - Id da melhor resposta a pergunta
     * @param pontuacaoBestA -Pontuação da melhor resposta a pergunta
     * @param tags -Lista das tags associadas a pergunta
     */

    public Question(long id, LocalDate date, String titulo, int nRespostas, long autor, long bestAnswer, float pontuacaoBestA, ArrayList<String> tags) {
        this.id = id;
        this.date = date;
        this.titulo = titulo;
        this.nRespostas = nRespostas;
        this.autor = autor;
        this.bestAnswer = bestAnswer;
        this.pontuacaoBestA = pontuacaoBestA;
        this.tags = tags;

    }

    //Gets e setters
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public LocalDate getDate() {
        return this.date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public String getTitulo() {
        return titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public int getnRespostas() {
        return nRespostas;
    }

    public void setnRespostas(int nRespostas) {
        this.nRespostas = nRespostas;
    }

    public long getAutor() {
        return autor;
    }

    public void setAutor(long autor) {
        this.autor = autor;
    }

    public long getBestAnswer() {
        return bestAnswer;
    }

    public void setBestAnswer(long bestAnswer) {
        this.bestAnswer = bestAnswer;
    }

    public float getPontuacaoBestA() {
        return pontuacaoBestA;
    }

    public void setPontuacaoBestA(float pontuacaoBestA) {
        this.pontuacaoBestA = pontuacaoBestA;
    }

    public ArrayList<String> getTags() {
        return tags;
    }

    public void setTags(ArrayList<String> tags) {
        this.tags = tags;
    }

    public int compareTag(String tag) {

        if(this.tags.contains(tag)){
            return 1;
        }

        return 0;
    }

    //ToString
    public String toString() {
        return "Question{" +
                "Id=" + id +
                ", Titulo='" + titulo + '\'' +
                ", Número Respostas=" + nRespostas +
                ", Autor=" + autor +
                ", Melhor Resposta=" + bestAnswer +
                ", Melhor Pontuação=" + pontuacaoBestA +
                ", Tags=" + tags +

                '}';
    }

    //Equals
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Question)) return false;
        Question question = (Question) o;
        return getId() == question.getId() &&
                getnRespostas() == question.getnRespostas() &&
                getAutor() == question.getAutor() &&
                getBestAnswer() == question.getBestAnswer() &&
                Float.compare(question.getPontuacaoBestA(), getPontuacaoBestA()) == 0 &&
                Objects.equals(getTitulo(), question.getTitulo()) &&
                Objects.equals(getTags(), question.getTags());
    }

    //Clone
    public Question clone(){

        return new Question(this.id, this.date, this.titulo, this.nRespostas, this.autor, this.bestAnswer, this.pontuacaoBestA, this.tags);
    }

}
