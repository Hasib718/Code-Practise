import java.util.Collections;
import java.util.List;

/**
 * This class is a example of Immutable objects
 */
public final class ImmutablePerson {
    private final String name;
    private final int age;
    private final List<String> friends;

    public ImmutablePerson(String name, int age, List<String> friends) {
        this.name = name;
        this.age = age;
        this.friends = friends;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    public List<String> getFriends() {
        return Collections.unmodifiableList(friends);
    }
}
