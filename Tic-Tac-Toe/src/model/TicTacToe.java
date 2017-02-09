package model;

import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Rectangle;

import java.io.IOException;
import java.util.List;

/**
 * Created by Sidney on 2/9/2017.
 */
public class TicTacToe {
    public Square[] getSquares() {
        return squares;
    }
    public void setSquares(Square[] squares) {
        this.squares = squares;
    }

    private Square[] squares;
    private int squaresOccupied;
    private SquareEnum turn = SquareEnum.CROSS;
    public Computer computer;

    public TicTacToe() {
        squares = new Square[9];
        for (int i = 0; i < 9; i++) {
            squares[i] = new Square(SquareEnum.EMPTY);
        }
        squaresOccupied = 0;
    }

    public String hasPlayerWon(){
        if(squares[0].getSquareEnum() == SquareEnum.CIRCLE && squares[1].getSquareEnum() == SquareEnum.CIRCLE && squares[2].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[3].getSquareEnum() == SquareEnum.CIRCLE && squares[4].getSquareEnum() == SquareEnum.CIRCLE && squares[5].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[6].getSquareEnum() == SquareEnum.CIRCLE && squares[7].getSquareEnum() == SquareEnum.CIRCLE && squares[8].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[0].getSquareEnum() == SquareEnum.CIRCLE && squares[3].getSquareEnum() == SquareEnum.CIRCLE && squares[6].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[1].getSquareEnum() == SquareEnum.CIRCLE && squares[4].getSquareEnum() == SquareEnum.CIRCLE && squares[7].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[3].getSquareEnum() == SquareEnum.CIRCLE && squares[5].getSquareEnum() == SquareEnum.CIRCLE && squares[8].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[0].getSquareEnum() == SquareEnum.CIRCLE && squares[4].getSquareEnum() == SquareEnum.CIRCLE && squares[8].getSquareEnum() == SquareEnum.CIRCLE ||
                squares[2].getSquareEnum() == SquareEnum.CIRCLE && squares[4].getSquareEnum() == SquareEnum.CIRCLE && squares[6].getSquareEnum() == SquareEnum.CIRCLE) {
            return "AI";
        } else if(squares[0].getSquareEnum() == SquareEnum.CROSS && squares[1].getSquareEnum() == SquareEnum.CROSS && squares[2].getSquareEnum() == SquareEnum.CROSS ||
                squares[3].getSquareEnum() == SquareEnum.CROSS && squares[4].getSquareEnum() == SquareEnum.CROSS && squares[5].getSquareEnum() == SquareEnum.CROSS ||
                squares[6].getSquareEnum() == SquareEnum.CROSS && squares[7].getSquareEnum() == SquareEnum.CROSS && squares[8].getSquareEnum() == SquareEnum.CROSS ||
                squares[0].getSquareEnum() == SquareEnum.CROSS && squares[3].getSquareEnum() == SquareEnum.CROSS && squares[6].getSquareEnum() == SquareEnum.CROSS ||
                squares[1].getSquareEnum() == SquareEnum.CROSS && squares[4].getSquareEnum() == SquareEnum.CROSS && squares[7].getSquareEnum() == SquareEnum.CROSS ||
                squares[2].getSquareEnum() == SquareEnum.CROSS && squares[5].getSquareEnum() == SquareEnum.CROSS && squares[8].getSquareEnum() == SquareEnum.CROSS ||
                squares[0].getSquareEnum() == SquareEnum.CROSS && squares[4].getSquareEnum() == SquareEnum.CROSS && squares[8].getSquareEnum() == SquareEnum.CROSS ||
                squares[2].getSquareEnum() == SquareEnum.CROSS && squares[4].getSquareEnum() == SquareEnum.CROSS && squares[6].getSquareEnum() == SquareEnum.CROSS) {
            return "Player";
        }
        return "";
    }

    public void squareClicked(int index) throws IOException {
        if (squares[index].getSquareEnum() == SquareEnum.EMPTY) {
            if (turn == SquareEnum.CROSS) {
                Image img = new Image(getClass().getResource("/resources/images/cross.png").toString());
                squares[index].getRectangle().setFill(new ImagePattern(img));
                squares[index].setSquareEnum(SquareEnum.CROSS);
                squaresOccupied += 1;

                // give turn to other
                turn = SquareEnum.CIRCLE;
            } else if (turn == SquareEnum.CIRCLE) {
                Image img = new Image(getClass().getResource("/resources/images/circle.png").toString());
                squares[index].getRectangle().setFill(new ImagePattern(img));
                squares[index].setSquareEnum(SquareEnum.CIRCLE);
                squaresOccupied += 1;

                turn = SquareEnum.CROSS;
                computerTurn();
            }
        }
        gameResult();
    }

    private void computerTurn() throws IOException {
        int index = 0;
        while(index < 9) {
            if (findAndDoBestComputerMove(squares[index]))
                break;
            index++;
        }
        squareClicked(index);
    }

    private boolean findAndDoBestComputerMove(Square square) {
        return false;
    }

    private List<Move> getPossibleMoves() {

        return null;
    }

    private void gameResult() {
        if (hasPlayerWon().equals("AI")) {
            alert("AI (circle) has won the game!");
        }
        if(hasPlayerWon().equals("Player")) {
            alert("Player (cross) has won the game!");
        }
        if(squaresOccupied == 9) {
            alert("Game ended as a draw!");
        }
    }

    private void alert(String content) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle("Information Dialog");
        alert.setHeaderText(null);
        alert.setContentText(content);
        alert.showAndWait();
        resetField();
    }

    private void resetField() {
        for (int i = 0; i < 9; i++) {
            squares[i].setSquareEnum(SquareEnum.EMPTY);
            squares[i].getRectangle().setFill(Color.WHITE);
        }
        squaresOccupied = 0;
    }
}
