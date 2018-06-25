package engine;

import java.time.LocalDate;
import java.util.*;

    /**
    *  Classe que caracteriza uma resposta (Answer) a uma pergunta (Question)
    *  É definida pelas suas variaveis de instancia: id da resposta, data da resposta, id da pergunta a que responde,
    *  autor da resposta e número de votos da resposta.
    */
public class Answer {
    private long id;
    private LocalDate date;
    private long idpai;
    private long autor;
    private int votes;

        /**
         * Construtor parametrizado da classe Answer.
         * @param id - Id que identifica a resposta
         * @param date - Data em que a resposta foi criada
         * @param idpai - Id da respetiva pergunta, para qual a resposta foi criada
         * @param autor - Id do autor que criou a resposta.
         * @param votes - Número de votos da resposta
         */

    public Answer(long id, LocalDate date, long idpai, long autor, int votes) {
        this.id = id;
        this.date = date;
        this.idpai = idpai;
        this.autor = autor;
        this.votes = votes;
    }

        /**
         * Construtor por copia da classe Answer.
         * @param a- Um objecto da classe Answer do qual se vai criar uma copia,
         */
    public Answer(Answer a){
        this.id = a.getId();
        this.date = a.getDate();
        this.idpai = a.getIdpai();
        this.autor = a.getAutor();
        this.votes = a.getVotes();

    }

    //Gets and Setters
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public long getIdpai() {
        return idpai;
    }

    public void setIdpai(long idpai) {
        this.idpai = idpai;
    }

    public long getAutor() {
        return autor;
    }

    public void setAutor(long autor) {
        this.autor = autor;
    }

    public int getVotes() {
        return votes;
    }

    public void setVotes(int votes) {
        this.votes = votes;
    }

    //ToString
    public String toString() {
        return "Answer{" +
                "Id=" + id +
                ", ID pai=" + idpai +
                ", Autor=" + autor +
                ", Votos=" + votes +
                '}';
    }

    //Equals
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Answer)) return false;
        Answer answer = (Answer) o;
        return getId() == answer.getId() &&
                getIdpai() == answer.getIdpai() &&
                getAutor() == answer.getAutor() &&
                getVotes() == answer.getVotes();
    }
    //Clone
    public Answer clone(){
        return new Answer(this.id, this.date, this.idpai, this.autor, this.votes);
    }
}
