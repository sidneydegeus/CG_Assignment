package model;

import javafx.scene.shape.Rectangle;

import java.io.IOException;

/**
 * Created by Jordan on 9-2-2017.
 */
public class Computer {
    private SquareEnum[] squareEnums;
    private TicTacToe ticTacToe;
    private int row, column;
    private Rectangle rectangle;

    public Computer(SquareEnum[] squareEnums){
        this.squareEnums = squareEnums;
        movePlayer();
    }

    public void movePlayer() {

    }
}
