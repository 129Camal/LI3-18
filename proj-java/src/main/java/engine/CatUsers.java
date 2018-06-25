package engine;


import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.stream.Collectors;

/**
 * Classe que define um coletivo de utilizadors(Person).
 * A sua variavél de instancia é um mapa cujo a chave é o id do utilizador e o value é o próprio utilizador(Person)
 */
public class CatUsers {
    private Map<Long, Person> users;

    /**
     * Construtor por vázio da classe CatUsers
     */
    public CatUsers() {
        this.users = new HashMap<>();
    }

    public Person getUser(long id){
        Person user = null;

        if(this.users.containsKey(id)) {
            user = this.users.get(id).clone();
        }

        return user;
    }

    public void setUser(long id, Person user){

        this.users.put(id,user);

    }

    public void free() {

        this.users.clear();
    }

    public int getSize(){

        return this.users.size();
    }

    public void incrementPosts(long id){

        this.users.get(id).setNposts();

    }

    public List<Long> topMostAtive(int size){
        List<Long> temp;
        
        // Criar comparador
        ComparatorMostActive comparador = new ComparatorMostActive();

        Integer i = Integer.valueOf(size);
        long s = i.longValue();

        temp = this.users.values().stream()
                                    .sorted(comparador)
                                    .limit(s)
                                    .map(e -> e.getId())
                                    .collect(Collectors.toCollection(ArrayList::new));
        return temp;              
    }

    public Map<Long, Person> getUsers() {
        return this.users.entrySet().stream().collect(Collectors.toMap(f->f.getKey(), f->f.getValue().clone()));
    }
}
