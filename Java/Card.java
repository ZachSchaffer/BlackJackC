public class Card {

    private int rank;
    private char suit;

    public Card(int rank, char suit) {

        this.rank = rank;
        this.suit = suit;

    }

    public int getRank() {

        return rank;
    }

    public int getSuit() {

        return suit;
    }

    public String toString() {

        String result = "";

        if (rank == 11) {
            result += 'J';
        } else if (rank == 12) {
            result += 'Q';
        } else if (rank == 13) {
            result += 'K';
        } else if (rank == 14) {
            result += 'A';
        } else
            result += rank;

        return result + suit;

    }

}
