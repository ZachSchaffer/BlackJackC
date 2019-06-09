public class Deck {

    public Deck() {
        int count = 0;
        char[] suits = {'c', 'd', 'h', 's'};
        for (int i = 2; i < 15; i++) {
            for (char c : suits) {
                deck[count] = new Card(i, c);
                count++;
            }
        }
    }

    public Card deal() {

    }

}



