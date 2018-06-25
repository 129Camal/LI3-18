package engine;

import common.MyLog;
import common.Pair;
import li3.TADCommunity;

import javax.xml.stream.XMLStreamException;
import java.io.FileNotFoundException;
import java.text.DateFormat;
import java.text.ParseException;
import java.time.LocalDate;
import java.util.*;
import java.util.function.Function;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.toCollection;
import static java.util.stream.Collectors.toMap;

/**
 * Classe principal, que permite processar a informação recebida e de realizar as queries,
 */
public class TCDExample implements TADCommunity{
    private MyLog qelog;
    private CatUsers users;
    private CatAnswers answers;
    private CatQuestions questions;
    private CatTags tags;
    private Parser parse;


    /**
     * Construtor vazio dum Objeto da Classe TCDExample
     */
    public TCDExample() {
        this.qelog = new MyLog("queryengine");
        this.users = new CatUsers();
        this.answers = new CatAnswers();
        this.questions = new CatQuestions();
        this.tags = new CatTags();
        this.parse = new Parser();
    }

    /**
     * Metodo que faz load da informação a ser processada
     * @param dumpPath - Caminho para o ficheiro que contem a informação
     */
    public void load(String dumpPath) throws FileNotFoundException, XMLStreamException, ParseException {
        String userpath = new StringBuilder().append(dumpPath).append("Users.xml").toString();
        String postspath = new StringBuilder().append(dumpPath).append("Posts.xml").toString();
        String tagspath = new StringBuilder().append(dumpPath).append("Tags.xml").toString();

        parse.parseUsers(userpath, this.users);
        parse.parsePosts(postspath, this.answers, this.questions, this.users);
        parse.parseTags(tagspath, this.tags);

        System.out.println("Users: " + this.users.getSize());
        System.out.println("Perguntas: " + this.questions.getSize());
        System.out.println("Respostas: " + this.answers.getSize());
        System.out.println("Tags: " + this.tags.getSize());


    }

    // Query 1

    /**
     * Metodo para resolver a primeira query.
     * @param id - Id do post de qual se quer o titulo do post e o nome do autor.
     * @return Retorna o titulo e o nome do autor da pergunta.
     */
    public Pair<String,String> infoFromPost(long id) {
        String titulo = "NULL";
        long autor = -1;
        long pai = -1;
        String nome = "NULL";

        if(this.answers.contains(id)){
            Answer a = this.answers.getAnswer(id);
            pai = a.getIdpai();
            Question q = this.questions.getQuestion(pai);
            titulo = q.getTitulo();
            autor = q.getAutor();

            Person p = this.users.getUser(autor);
            nome = p.getNome();
        }

        if(this.questions.contains(id)){

            Question q = this.questions.getQuestion(id);
            titulo = q.getTitulo();
            autor = q.getAutor();

            Person p = this.users.getUser(autor);
            nome = p.getNome();
        }
        return new Pair(titulo, nome);
    }

    // Query 2
    /**
     * Metodo para resolver a segunda query.
     * @param n - Número de utilizadores que se quer obter.
     * @return Retorna os N utilizadores com o maior número de posts(perguntas e respostas)
     */
    public List<Long> topMostActive(int n) {
        
        List<Long> result = this.users.topMostAtive(n);
        
        return result;
    }

    // Query 3

    /**
     * Metodo que resolve a terceira query
     * @param begin - data de inicio da procura
     * @param end - data do fim da procura
     * @return Retorna o total de posts nesse periodo de tempo e identifica-os por pergunta e resposta.
     */
    public Pair<Long,Long> totalPosts(LocalDate begin, LocalDate end) {
        System.out.println(begin);
        System.out.println(end);
        long resultQuestions = this.questions.getQuestions().values().stream()
                                                            .filter(e -> e.getDate().compareTo(end) <= 0 && e.getDate().compareTo(begin) >= 0)
                                                            .count();
        long resultAnswers = this.answers.getAnswers().values().stream()
                                                               .filter(e -> e.getDate().compareTo(end) <= 0 && e.getDate().compareTo(begin) >= 0)
                                                                .count();

        return new Pair(Long.valueOf(resultQuestions),Long.valueOf(resultAnswers));
    }

    // Query 4

    /**
     * Metodo que resolve a quarta query
     * @param tag - tag em qual se vai basear a procura
     * @param begin -Data de inicio da procura
     * @param end -Data do fim da procura
     * @return Retorna todas as perguntas em que a tag foi utilizada, por ordem cronologica inversa.
     */
    public List<Long> questionsWithTag(String tag, LocalDate begin, LocalDate end) {
        ComparatorDatesQuestion comparador = new ComparatorDatesQuestion();

        ArrayList<Long> result = this.questions.getQuestions().values().stream()
                                                                        .filter(e -> e.getDate().compareTo(end) <= 0 && e.getDate().compareTo(begin) >= 0)
                                                                        .sorted(comparador)
                                                                        .filter(e -> e.compareTag(tag) > 0)
                                                                        .map(Question::getId)
                                                                        .collect(Collectors.toCollection(ArrayList::new));

        return result;
    }

    // Query 5

    /**
     * Metodo que resolve a query 5
     * @param id - Id do utilizador de qual se quer a informação
     * @return Retorna o texto de apresentação do id escolhido e também os seus ultimos 10 posts criados.
     */
    public Pair<String, List<Long>> getUserInfo(long id){
        String shortBio = "NULL";
        shortBio = this.users.getUser(id).getAboutme();
        ComparatorQuestionsEntry comparador1 = new ComparatorQuestionsEntry();
        ComparatorAnswersEntry comparador2 = new ComparatorAnswersEntry();
        Comparator<Map.Entry<LocalDate,Long>> comparador3 = new ComparatorDatePosts();

        Map<LocalDate, Long> result = new HashMap<>();

        this.questions.getQuestions().entrySet().stream().filter(e -> e.getValue().getAutor() == id)
                                                                            .sorted(comparador1)
                                                                            .limit(10)
                                                                            .forEach( e -> result.put(e.getValue().getDate(), e.getValue().getId()) );


        Map<LocalDate, Long> ans = new HashMap<>();

        this.answers.getAnswers().entrySet().stream().filter(e -> e.getValue().getAutor() == id)
                                                                     .sorted(comparador2)
                                                                     .limit(10)
                                                                     .forEach( e -> result.put(e.getValue().getDate(), e.getValue().getId()) );


        ArrayList<Long> ids = result.entrySet().stream()
                                               .sorted(comparador3)
                                               .limit(10)
                                               .map(e-> e.getValue())
                                               .collect(Collectors.toCollection(ArrayList::new));

        return new Pair(shortBio,ids);
    }

    // Query 6

    /**
     * Metodo que resolve a sexta query.
     * @param N - Número de respostas que se quer obter
     * @param begin - Data de inicio de procura
     * @param end -Data de fim de procura
     * @return Retorna as N respostas com o maior numero de votos.
     */
    public List<Long> mostVotedAnswers(int N, LocalDate begin, LocalDate end) {

        ComparatorVotes comparador = new ComparatorVotes();
        ArrayList<Long> result = this.answers.getAnswers().values().stream()
                                                          .filter(e -> e.getDate().compareTo(end) <= 0 && e.getDate().compareTo(begin) >= 0)
                                                          .sorted(comparador)
                                                          .limit(N)
                                                          .map(e -> e.getId())
                                                          .collect(Collectors.toCollection(ArrayList::new));
        return result;
    }

    // Query 7

    /**
     * Metodo que resolve a setima query.
     * @param N - número de perguntas que se quer receber
     * @param begin - data de inicio de procura
     * @param end- data do fim de procura
     * @return Retorna as N perguntas com maior número de respostas nesse intervalo de tempo.
     */
    public List<Long> mostAnsweredQuestions(int N, LocalDate begin, LocalDate end) {
        ComparatorAnswers comparador = new ComparatorAnswers();

        ArrayList<Long> result = this.questions.getQuestions().values().stream()
                                                                        .filter(e -> e.getDate().compareTo(end) <= 0 && e.getDate().compareTo(begin) >= 0)
                                                                        .sorted(comparador)
                                                                        .limit(N)
                                                                        .map(e -> e.getId())
                                                                        .collect(Collectors.toCollection(ArrayList::new));
        return result;
    }

    // Query 8

    /**
     * Metodo que resolve a oitava query.
     * @param N -número de titulos que se quer obter.
     * @param word - palavra que se vai basear a perquisa
     * @return Retorna as n respostas que contem a palavra no titulo.
     */
    public List<Long> containsWord(int N, String word) {

        ComparatorDatesQuestion comparador = new ComparatorDatesQuestion();

        ArrayList<Long> result = this.questions.getQuestions().values().stream()
                                                                        .filter(e -> e.compareTag(word) > 0)
                                                                        .sorted(comparador)
                                                                        .limit(N)
                                                                        .map(e -> e.getId())
                                                                        .collect(Collectors.toCollection(ArrayList::new));

        return result;
    }

    // Query 9

    /**
     * Metodo que resolve a nona query
     * @param N - Número de perguntas que se quer obter
     * @param id1 - id do primeiro utilizador
     * @param id2 - id do segundo utilizador
     * @return Retorna as N perguntas em que participaram os dois utilizadores.
      */
    public List<Long> bothParticipated(int N, long id1, long id2) {
        ComparatorQuestionsEntry comparador1 = new ComparatorQuestionsEntry();
        ComparatorAnswersEntry comparador2 = new ComparatorAnswersEntry();
        ComparatorDatePostsNine comparador3 = new ComparatorDatePostsNine();

        Map<Long, LocalDate> result1 = new HashMap<>();
        Map<Long, LocalDate> result2 = new HashMap<>();
        ArrayList<Long> retorno = new ArrayList<>();


        this.questions.getQuestions().entrySet().stream().filter(e -> e.getValue().getAutor() == id1)
                                                         .sorted(comparador1)
                                                         .forEach( e -> result1.put(e.getValue().getId(), e.getValue().getDate()));

        this.questions.getQuestions().entrySet().stream().filter(e -> e.getValue().getAutor() == id2)
                                                         .sorted(comparador1)
                                                         .forEach( e -> result2.put(e.getValue().getId(), e.getValue().getDate()));

        this.answers.getAnswers().entrySet().stream().filter(e -> e.getValue().getAutor() == id1)
                                                     .sorted(comparador2)
                                                     .forEach( e -> result1.put(e.getValue().getIdpai(), e.getValue().getDate()));

        this.answers.getAnswers().entrySet().stream().filter(e -> e.getValue().getAutor() == id2)
                                                     .sorted(comparador2)
                                                     .forEach( e -> result2.put(e.getValue().getIdpai(), e.getValue().getDate()));

        System.out.println(result1.size());
        System.out.println(result2.size());

        ArrayList<Long> fim1 = result1.entrySet().stream().sorted(comparador3).map(e -> Long.valueOf(e.getKey())).collect(Collectors.toCollection(ArrayList::new));

        ArrayList<Long> fim2 = result2.entrySet().stream().sorted(comparador3).map(e -> Long.valueOf(e.getKey())).collect(Collectors.toCollection(ArrayList::new));

        for(Long l : fim1){
            System.out.println(l);
            if(fim2.contains(l)){
                retorno.add(l);
            }
        }
        return retorno;
    }

    // Query 10

    /**
     * Metodo que resolve a decima pergunta
     * @param id- Id da pergunta de qual se quer a resposta
     * @return Retorna a resposta com melhor score.
     */
    public long betterAnswer(long id) {
        long bestAnswer = this.questions.getBetterAnswer(id);

        return bestAnswer;
    }

    // Query 11

    /**
     * Metodo que resolve a decima primeira query.
     * @param N -O número de tags que se quer obter
     * @param begin -Data de inicio de procura
     * @param end - Data de fim de procura.
     * @return Retorna os N número de tags mais usados pelos N utilizadores com a melhor reputação.
     */
    public List<Long> mostUsedBestRep(int N, LocalDate begin, LocalDate end) {

        ComparatorReputation comparador = new ComparatorReputation();

        ArrayList<String> postsTags = new ArrayList<>();

        ArrayList<Long> resultUsers = this.users.getUsers().values().stream()
                                                                    .sorted(comparador)
                                                                    .limit(N)
                                                                    .map(e-> Long.valueOf(e.getId()))
                                                                    .collect(Collectors.toCollection(ArrayList::new));

        this.questions.getQuestions().values().stream()
                                              .filter(e -> e.getDate().compareTo(end) <= 0 && e.getDate().compareTo(begin) >= 0 && resultUsers.contains(Long.valueOf(e.getAutor())))
                                              .map(e -> e.getTags())
                                              .forEach(e-> postsTags.addAll(e));

        Map<String, Long> res2 = postsTags.stream().collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

        Map<String, Long> result = res2.entrySet().stream().sorted(Map.Entry.<String, Long>comparingByValue().reversed()).collect(toMap(Map.Entry::getKey, Map.Entry::getValue, (e1,e2) -> e1, LinkedHashMap::new));

        ArrayList<Long> fim = new ArrayList<>();
                result.keySet().stream().limit(N).forEach(e -> fim.add(this.tags.pickTags(e)));

        return fim;

    }

    public void clear(){
        this.users.free();
        this.questions.free();
        this.answers.free();
        this.tags.free();
    }
}
