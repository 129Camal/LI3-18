package engine;

import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamConstants;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.time.LocalDate.parse;
import static java.time.format.DateTimeFormatter.ISO_LOCAL_DATE;
import static java.time.format.DateTimeFormatter.ISO_LOCAL_DATE_TIME;


public class Parser {
    public static void parseUsers(String path, CatUsers structure) throws FileNotFoundException, XMLStreamException {

        long id, reputation;
        String name;
        String about;
        Person person;

        XMLInputFactory factory = XMLInputFactory.newInstance();

        factory.setProperty("javax.xml.stream.isCoalescing", true);

        XMLStreamReader reader = factory.createXMLStreamReader(new FileInputStream(path));

        while (reader.hasNext()) {
            int event = reader.next();

            switch (event) {
                case XMLStreamConstants.END_DOCUMENT:
                    reader.close();
                    break;

                case XMLStreamConstants.START_ELEMENT:
                    if (reader.getLocalName().equals("row")) {
                        id = Long.parseLong(reader.getAttributeValue(null, "Id"));

                        if (id > 0) {
                            reputation = Long.parseLong(reader.getAttributeValue(null, "Reputation"));
                            name = reader.getAttributeValue(null, "DisplayName");
                            about = reader.getAttributeValue(null, "AboutMe");

                            person = new Person(id, name, about, reputation, 0);
                            structure.setUser(id, person);
                        }
                    }
            }

        }
    }

    public static void parsePosts(String path, CatAnswers answers, CatQuestions questions, CatUsers users) throws FileNotFoundException, XMLStreamException, ParseException {

        int votes, nRespostas, com;
        String titulo, tags;
        long id, autor, idpai, postype, reputacao;

        LocalDate date;
        Question q;
        Answer a;

        XMLInputFactory factory = XMLInputFactory.newInstance();

        factory.setProperty("javax.xml.stream.isCoalescing", true);

        XMLStreamReader reader = factory.createXMLStreamReader(new FileInputStream(path));

        while (reader.hasNext()) {
            int event = reader.next();

            switch (event) {
                case XMLStreamConstants.END_DOCUMENT:
                    reader.close();
                    break;

                case XMLStreamConstants.START_ELEMENT:
                    if (reader.getLocalName().equals("row")) {
                        postype = Long.parseLong(reader.getAttributeValue(null, "PostTypeId"));
                        autor = Long.parseLong(reader.getAttributeValue(null, "OwnerUserId"));

                        if (postype == 1 && autor != -1) {
                            id = Long.parseLong(reader.getAttributeValue(null, "Id"));
                            titulo = reader.getAttributeValue(null, "Title");
                            nRespostas = Integer.parseInt(reader.getAttributeValue(null, "AnswerCount"));
                            date = parse(reader.getAttributeValue(null, "CreationDate"), ISO_LOCAL_DATE_TIME);

                            tags = reader.getAttributeValue(null, "Tags");


                            ArrayList<String> arrayTags = new ArrayList<String>();
                            StringTokenizer s = new StringTokenizer(tags, "<>");

                            while (s.hasMoreTokens()) {
                                String token = s.nextToken();
                                arrayTags.add(token);
                            }

                            q = new Question(id, date, titulo, nRespostas, autor, -1, 0, arrayTags);

                            questions.setQuestions(id, q);

                            users.incrementPosts(autor);


                        }
                        if (postype == 2 && autor != -1) {
                            id = Long.parseLong(reader.getAttributeValue(null, "Id"));
                            date = parse(reader.getAttributeValue(null, "CreationDate"), ISO_LOCAL_DATE_TIME);
                            idpai = Long.parseLong(reader.getAttributeValue(null, "ParentId"));
                            votes = Integer.parseInt(reader.getAttributeValue(null, "Score"));
                            com = Integer.parseInt(reader.getAttributeValue(null, "CommentCount"));

                            a = new Answer(id, date, idpai, autor, votes);
                            answers.setAnswer(id, a);

                            if (questions.getQuestion(idpai) != null) {
                                reputacao = users.getUser(autor).getReputacao();

                                float result = (float) (votes * 0.65 + reputacao * 0.25 + com * 0.1);

                                if (result > questions.getQuestion(idpai).getPontuacaoBestA()) {

                                    questions.setBetterAnswer(idpai, id);
                                    questions.setPontuacaoBestA(idpai, result);

                                }
                            }
                            users.incrementPosts(autor);

                        }
                    }

            }
        }
    }

    public static void parseTags(String path, CatTags structure) throws FileNotFoundException, XMLStreamException {
        String nome;
        long id;
        Tag tag;

        XMLInputFactory factory = XMLInputFactory.newInstance();

        factory.setProperty("javax.xml.stream.isCoalescing", true);

        XMLStreamReader reader = factory.createXMLStreamReader(new FileInputStream(path));

        while (reader.hasNext()) {
            int event = reader.next();

            switch (event) {
                case XMLStreamConstants.END_DOCUMENT:
                    reader.close();
                    break;

                case XMLStreamConstants.START_ELEMENT:
                    if (reader.getLocalName().equals("row")) {
                        id = Long.parseLong(reader.getAttributeValue(null, "Id"));
                        nome = reader.getAttributeValue(null, "TagName");

                        tag = new Tag(id,nome,0);

                        structure.setTag(nome,tag);
                    }

            }

        }
    }
}