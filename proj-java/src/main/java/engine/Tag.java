package engine;


import java.util.Objects;

/**
 * Classe que define uma Tag.
 * Tem como variavéis de instáncia: o id de identificação da tag, o nome da tag e o contador de quantos vezes ela foi
 * usada.
 */
public class Tag {
    private long id;
    private String nome;
    private int contador;

    /**
     * Construtor parametrizado da classe Tag.
     * @param id - Id da tag
     * @param nome - Nome da tag
     * @param contador - Contador de quantas vezes a tag foi usada
     */
    public Tag(long id, String nome, int contador) {
        this.id = id;
        this.nome = nome;
        this.contador = contador;
    }

    /**
     * Construtor por copia da classe Tag
     * @param a - um objecto da classe Tag de qual se vai fazer uma copia.
     */
    public Tag (Tag a){
        this.id = a.getId();
        this.nome = a.getNome();
        this.contador = a.getContador();
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

    public int getContador() {
        return contador;
    }

    public void setContador() {
        this.contador = this.contador + 1;
    }

    //ToString
    public String toString() {
        return "Tag{" +
                "Id=" + id +
                ", Nome='" + nome + '\'' +
                ", Contador=" + contador +
                '}';
    }

    //Equals
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Tag)) return false;
        Tag tag = (Tag) o;
        return getId() == tag.getId() &&
                getContador() == tag.getContador() &&
                Objects.equals(getNome(), tag.getNome());
    }

    //Clone
    public Tag clone (){
        return new Tag (this.id, this.nome, this.contador);
    }


}
