package model;

import javafx.scene.control.Alert;
import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.paint.ImagePattern;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Sidney on 2/9/2017.
 */
public class TicTacToe {
    public Square[] getBoard() {
        return board;
    }
    public void setBoard(Square[] board) {
        this.board = board;
    }

    private Square[] board;
    private List<MoveAndScores> moveAndScores;
    private int squaresOccupied;
    private SquareEnum turn = SquareEnum.CROSS;
    public Computer computer;

    public TicTacToe() {
        board = new Square[9];
        for (int i = 0; i < 9; i++) {
            board[i] = new Square(SquareEnum.EMPTY);
        }
        squaresOccupied = 0;
    }

    public SquareEnum getTurn(){
        return turn;
    }
    public void setTurn(SquareEnum turn){
        this.turn = turn;
    }

    public SquareEnum getSquare(int index){
        return board[index].getSquareEnum();
    }
    public void setSquare(int index, SquareEnum squareEnum){
        board[index].setSquareEnum(squareEnum);
    }

    public String hasPlayerWon(){
        if(board[0].getSquareEnum() == SquareEnum.CIRCLE && board[1].getSquareEnum() == SquareEnum.CIRCLE && board[2].getSquareEnum() == SquareEnum.CIRCLE ||
                board[3].getSquareEnum() == SquareEnum.CIRCLE && board[4].getSquareEnum() == SquareEnum.CIRCLE && board[5].getSquareEnum() == SquareEnum.CIRCLE ||
                board[6].getSquareEnum() == SquareEnum.CIRCLE && board[7].getSquareEnum() == SquareEnum.CIRCLE && board[8].getSquareEnum() == SquareEnum.CIRCLE ||
                board[0].getSquareEnum() == SquareEnum.CIRCLE && board[3].getSquareEnum() == SquareEnum.CIRCLE && board[6].getSquareEnum() == SquareEnum.CIRCLE ||
                board[1].getSquareEnum() == SquareEnum.CIRCLE && board[4].getSquareEnum() == SquareEnum.CIRCLE && board[7].getSquareEnum() == SquareEnum.CIRCLE ||
                board[3].getSquareEnum() == SquareEnum.CIRCLE && board[5].getSquareEnum() == SquareEnum.CIRCLE && board[8].getSquareEnum() == SquareEnum.CIRCLE ||
                board[0].getSquareEnum() == SquareEnum.CIRCLE && board[4].getSquareEnum() == SquareEnum.CIRCLE && board[8].getSquareEnum() == SquareEnum.CIRCLE ||
                board[2].getSquareEnum() == SquareEnum.CIRCLE && board[4].getSquareEnum() == SquareEnum.CIRCLE && board[6].getSquareEnum() == SquareEnum.CIRCLE) {
            return "AI";
        } else if(board[0].getSquareEnum() == SquareEnum.CROSS && board[1].getSquareEnum() == SquareEnum.CROSS && board[2].getSquareEnum() == SquareEnum.CROSS ||
                board[3].getSquareEnum() == SquareEnum.CROSS && board[4].getSquareEnum() == SquareEnum.CROSS && board[5].getSquareEnum() == SquareEnum.CROSS ||
                board[6].getSquareEnum() == SquareEnum.CROSS && board[7].getSquareEnum() == SquareEnum.CROSS && board[8].getSquareEnum() == SquareEnum.CROSS ||
                board[0].getSquareEnum() == SquareEnum.CROSS && board[3].getSquareEnum() == SquareEnum.CROSS && board[6].getSquareEnum() == SquareEnum.CROSS ||
                board[1].getSquareEnum() == SquareEnum.CROSS && board[4].getSquareEnum() == SquareEnum.CROSS && board[7].getSquareEnum() == SquareEnum.CROSS ||
                board[2].getSquareEnum() == SquareEnum.CROSS && board[5].getSquareEnum() == SquareEnum.CROSS && board[8].getSquareEnum() == SquareEnum.CROSS ||
                board[0].getSquareEnum() == SquareEnum.CROSS && board[4].getSquareEnum() == SquareEnum.CROSS && board[8].getSquareEnum() == SquareEnum.CROSS ||
                board[2].getSquareEnum() == SquareEnum.CROSS && board[4].getSquareEnum() == SquareEnum.CROSS && board[6].getSquareEnum() == SquareEnum.CROSS) {
            return "Player";
        }
        return "";
    }

    public void squareClicked(int index) throws IOException {
        if (board[index].getSquareEnum() == SquareEnum.EMPTY) {
            if (turn == SquareEnum.CROSS) { // player
                Image img = new Image(getClass().getResource("/resources/images/cross.png").toString());
                board[index].getRectangle().setFill(new ImagePattern(img));
                board[index].setSquareEnum(SquareEnum.CROSS);
                squaresOccupied += 1;
                // give turn to other
                turn = SquareEnum.CIRCLE;
                performAIMove();
            }
        }
        gameResult();
    }

    public void performAIMove() {
        callMiniMax(0, SquareEnum.CIRCLE);
        Move bestMove = returnBestMove();
        int bestIndex = bestMove.getRow() * 3 + bestMove.getCol();

        Image img = new Image(getClass().getResource("/resources/images/circle.png").toString());
        board[bestIndex].getRectangle().setFill(new ImagePattern(img));
        board[bestIndex].setSquareEnum(SquareEnum.CIRCLE);
        squaresOccupied += 1;

        turn = SquareEnum.CROSS;
    }

    public void callMiniMax(int depth, SquareEnum turn) {
        moveAndScores = new ArrayList<>();
        miniMax(depth, turn);
    }

    public int miniMax(int depth, SquareEnum turn) {
        List<Move> nextMoves = getPossibleMoves();
        // if there are no more moves left, that means the game is a draw
        if (nextMoves.isEmpty())
            return 0;

        if (hasPlayerWon().equals("AI")) {
            return 1;
        } else if (hasPlayerWon().equals("Player")) {
            return -1;
        }

        List<Integer> scores = new ArrayList<>();

        for (Move move : nextMoves) {
            int index = move.getRow() * 3 + move.getCol();
            setSquare(index, turn); // try this move for the current player

            if (turn == SquareEnum.CIRCLE) { // ai
                int currentScore = miniMax(depth + 1, SquareEnum.CROSS);
                scores.add(currentScore);

                if (depth == 0)
                    moveAndScores.add(new MoveAndScores(currentScore, move));

            } else if (turn == SquareEnum.CROSS) { // player
                scores.add(miniMax(depth + 1, SquareEnum.CIRCLE));
            }
            board[index].setSquareEnum(SquareEnum.EMPTY); // reset the move that was made
        }
        return turn == SquareEnum.CIRCLE ? returnMax(scores) : returnMin(scores);
    }

    public List<Move> getPossibleMoves() {
        List<Move> nextMoves = new ArrayList<Move>();

        // If gameover, i.e., no next move
        if (hasPlayerWon().equals("AI") || hasPlayerWon().equals("Player")) {
            return nextMoves;   // return empty list
        }

        // Search for empty cells and add to the List
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                int index = row * 3 + col;
                if (board[index].getSquareEnum() == SquareEnum.EMPTY) {
                    nextMoves.add(new Move(row, col));
                }
            }
        }
        return nextMoves;
    }

    public Move returnBestMove() {
        int MAX = -100000;
        int best = -1;

        for (int i = 0; i < moveAndScores.size(); ++i) {
            if (MAX < moveAndScores.get(i).score) {
                MAX = moveAndScores.get(i).score;
                best = i;
            }
        }

        return moveAndScores.get(best).move;
    }

    public int returnMin(List<Integer> list) {
        int min = Integer.MAX_VALUE;
        int index = -1;
        for (int i = 0; i < list.size(); ++i) {
            if (list.get(i) < min) {
                min = list.get(i);
                index = i;
            }
        }
        return list.get(index);
    }

    public int returnMax(List<Integer> list) {
        int max = Integer.MIN_VALUE;
        int index = -1;
        for (int i = 0; i < list.size(); ++i) {
            if (list.get(i) > max) {
                max = list.get(i);
                index = i;
            }
        }
        return list.get(index);
    }

    private void gameResult() {
        if (hasPlayerWon().equals("AI")) {
            alert("AI (circle) has won the game!");
        }
        else if(hasPlayerWon().equals("Player")) {
            alert("Player (cross) has won the game!");
        }
        else if(squaresOccupied == 9) {
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
            board[i].setSquareEnum(SquareEnum.EMPTY);
            board[i].getRectangle().setFill(Color.WHITE);
        }
        squaresOccupied = 0;
    }
}
