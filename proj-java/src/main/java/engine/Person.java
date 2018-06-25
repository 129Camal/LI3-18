package engine;

import java.util.Arrays;
import java.util.Objects;

/**
 * Classe que caracteriza um utilizador(Person).
 * É definida pelas suas variaveis de instáncia: Id do utilizador, nome do utilizador, texto de apresentação/descrição,
 * reputação do utilizador e número total de posts criados pelo mesmo.
  */

public class Person {
    private long id;
    private String nome;
    private String aboutme;
    private long reputacao;
    private int nposts;

    /**
     *Construtor parametrizado da classe Person
     * @param id - Identificação do utilizador.
     * @param nome -Nome do utilizador.
     * @param aboutme - Texto de descrição do utilizador.
     * @param reputacao -Reputação do utilizador.
     * @param nposts -Número total de posts do utilizador.
     */
    public Person(long id, String nome, String aboutme, long reputacao, int nposts) {
        this.id = id;
        this.nome = nome;
        this.aboutme = aboutme;
        this.reputacao = reputacao;
        this.nposts = nposts;
    }

    /**
     * Construtor por copia da classe Person
     * @param a-  Um objecto Person do qual se vai criar uma copia.
     */
    public Person(Person a){
        this.id = a.getId();
        this.nome = a.getNome();
        this.aboutme = a.getAboutme();
        this.reputacao = a.getReputacao();
        this.nposts = a.getNposts();
    }

    //Setters e Getters
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getAboutme() {
        return aboutme;
    }

    public void setAboutme(String aboutme) {
        this.aboutme = aboutme;
    }

    public long getReputacao() {
        return reputacao;
    }

    public void setReputacao(long reputacao) {
        this.reputacao = reputacao;
    }

    public int getNposts() {
        return nposts;
    }

    public void setNposts() {
        this.nposts = (this.nposts)+1;
    }

    //toString
    public String toString() {
        return "Person{" +
                "Id=" + id +
                ", Nome='" + nome + '\'' +
                ", Aboutme='" + aboutme + '\'' +
                ", Reputacao=" + reputacao +
                ", Número de posts=" + nposts +
                '}';
    }

    //Equals
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Person)) return false;
        Person person = (Person) o;
        return getId() == person.getId() &&
                getReputacao() == person.getReputacao() &&
                getNposts() == person.getNposts() &&
                Objects.equals(getNome(), person.getNome()) &&
                Objects.equals(getAboutme(), person.getAboutme());
    }

    //Clone
    public Person clone(){
        return new Person(this.id, this.nome, this.aboutme, this.reputacao, this.nposts);
    }

}


