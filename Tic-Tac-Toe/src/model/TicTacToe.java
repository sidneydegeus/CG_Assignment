package model;

import javafx.scene.image.Image;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Rectangle;

import java.io.IOException;

/**
 * Created by Sidney on 2/9/2017.
 */
public class TicTacToe {
    private SquareEnum[] squareEnums;
    private int squaresOccupied;
    private SquareEnum turn = SquareEnum.CROSS;

    public TicTacToe() {
        squareEnums = new SquareEnum[9];
        for (int i = 0; i < 9; i++) {
            squareEnums[i] = SquareEnum.EMPTY;
        }
        squaresOccupied = 0;
    }

    public void squareClicked(Rectangle rectangle, int row, int column) throws IOException {
        int index = row * 3 + column;
        if (squareEnums[index] == SquareEnum.EMPTY) {
            if (turn == SquareEnum.CROSS) {
                Image img = new Image(getClass().getResource("/resources/images/cross.png").toString());

                rectangle.setFill(new ImagePattern(img));
                turn = SquareEnum.CIRCLE;
            } else if (turn == SquareEnum.CIRCLE) {
                Image img = new Image(getClass().getResource("/resources/images/circle.png").toString());
                rectangle.setFill(new ImagePattern(img));
                turn = SquareEnum.CROSS;
            }
        }

        System.out.println("clicked "  + index);
    }
}
