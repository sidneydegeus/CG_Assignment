package model;

/**
 * Created by Sidney on 2/9/2017.
 */
public class Move {
    int row, col;

    public Move(int row, int col) {
        this.row = row;
        this.col = col;
        //moves = new int[]{1, 2};
    }

    public int getRow() {
        return row;
    }
    public void setRow(int row) {
        this.row = row;
    }

    public int getCol() {
        return col;
    }
    public void setCol(int col) {
        this.col = col;
    }
}
