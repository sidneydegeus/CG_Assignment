package model;

import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
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
    public Computer computer;

    public TicTacToe() {
        squareEnums = new SquareEnum[9];
        for (int i = 0; i < 9; i++) {
            squareEnums[i] = SquareEnum.EMPTY;
        }
        squaresOccupied = 0;
    }

    public String hasPlayerWon(){
        if(squareEnums[0] == SquareEnum.CIRCLE && squareEnums[1] == SquareEnum.CIRCLE && squareEnums[2] == SquareEnum.CIRCLE ||
                squareEnums[3] == SquareEnum.CIRCLE && squareEnums[4] == SquareEnum.CIRCLE && squareEnums[5] == SquareEnum.CIRCLE ||
                squareEnums[6] == SquareEnum.CIRCLE && squareEnums[7] == SquareEnum.CIRCLE && squareEnums[8] == SquareEnum.CIRCLE ||
                squareEnums[0] == SquareEnum.CIRCLE && squareEnums[3] == SquareEnum.CIRCLE && squareEnums[6] == SquareEnum.CIRCLE ||
                squareEnums[1] == SquareEnum.CIRCLE && squareEnums[4] == SquareEnum.CIRCLE && squareEnums[7] == SquareEnum.CIRCLE ||
                squareEnums[2] == SquareEnum.CIRCLE && squareEnums[5] == SquareEnum.CIRCLE && squareEnums[8] == SquareEnum.CIRCLE ||
                squareEnums[0] == SquareEnum.CIRCLE && squareEnums[4] == SquareEnum.CIRCLE && squareEnums[8] == SquareEnum.CIRCLE ||
                squareEnums[2] == SquareEnum.CIRCLE && squareEnums[4] == SquareEnum.CIRCLE && squareEnums[6] == SquareEnum.CIRCLE) {
            return "AI";
        } else if(squareEnums[0] == SquareEnum.CROSS && squareEnums[1] == SquareEnum.CROSS && squareEnums[2] == SquareEnum.CROSS ||
                squareEnums[3] == SquareEnum.CROSS && squareEnums[4] == SquareEnum.CROSS && squareEnums[5] == SquareEnum.CROSS ||
                squareEnums[6] == SquareEnum.CROSS && squareEnums[7] == SquareEnum.CROSS && squareEnums[8] == SquareEnum.CROSS ||
                squareEnums[0] == SquareEnum.CROSS && squareEnums[3] == SquareEnum.CROSS && squareEnums[6] == SquareEnum.CROSS ||
                squareEnums[1] == SquareEnum.CROSS && squareEnums[4] == SquareEnum.CROSS && squareEnums[7] == SquareEnum.CROSS ||
                squareEnums[2] == SquareEnum.CROSS && squareEnums[5] == SquareEnum.CROSS && squareEnums[8] == SquareEnum.CROSS ||
                squareEnums[0] == SquareEnum.CROSS && squareEnums[4] == SquareEnum.CROSS && squareEnums[8] == SquareEnum.CROSS ||
                squareEnums[2] == SquareEnum.CROSS && squareEnums[4] == SquareEnum.CROSS && squareEnums[6] == SquareEnum.CROSS) {
            return "Player";
        }
        return "";
    }

    public void squareClicked(Rectangle rectangle, int row, int column) throws IOException {
        int index = row * 3 + column;
        if (squareEnums[index] == SquareEnum.EMPTY) {
            if (turn == SquareEnum.CROSS) {
                Image img = new Image(getClass().getResource("/resources/images/cross.png").toString());

                rectangle.setFill(new ImagePattern(img));
                turn = SquareEnum.CIRCLE;
                squareEnums[index] = SquareEnum.CROSS;
                squaresOccupied += 1;
                System.out.println(rectangle);
                computer = new Computer(squareEnums);
            } else if (turn == SquareEnum.CIRCLE) {
                Image img = new Image(getClass().getResource("/resources/images/circle.png").toString());
                rectangle.setFill(new ImagePattern(img));
                turn = SquareEnum.CROSS;
                squareEnums[index] = SquareEnum.CIRCLE;
                squaresOccupied += 1;
            }
        }

        System.out.println("clicked "  + index);

        if(hasPlayerWon().equals("AI")) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Information Dialog");
            alert.setHeaderText(null);
            alert.setContentText("AI (circle) has won the game!");

            alert.showAndWait();
            for (int i = 0; i < 9; i++) {
                squareEnums[i] = SquareEnum.EMPTY;
                //Ff functie voor alle plaatjes legen
            }
            squaresOccupied = 0;
        }
        if(hasPlayerWon().equals("Player")) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Information Dialog");
            alert.setHeaderText(null);
            alert.setContentText("Player (cross) has won the game!");

            alert.showAndWait();

            for (int i = 0; i < 9; i++) {
                squareEnums[i] = SquareEnum.EMPTY;
                //Ff functie voor alle plaatjes legen
            }
            squaresOccupied = 0;
        }
        if(squaresOccupied == 9) {
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Information Dialog");
            alert.setHeaderText(null);
            alert.setContentText("Game ended as a draw!");

            alert.showAndWait();

            for (int i = 0; i < 9; i++) {
                squareEnums[i] = SquareEnum.EMPTY;
                //Ff functie voor alle plaatjes legen
            }
        }

    }
}
