package tests;

import model.SquareEnum;
import model.TicTacToe;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by Jordan on 14-2-2017.
 */
public class TicTacToeTest {
    @Test
    public void testNew() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        assertEquals(SquareEnum.CROSS, ticTacToe.getTurn());
    }

    @Test
    public void testMove() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(2, SquareEnum.CROSS);
        assertEquals(SquareEnum.CROSS, ticTacToe.getSquare(2));
    }

    @Test
    public void testPossibleMoves() throws Exception {

    }

    @Test
    public void testWin() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(0, SquareEnum.CIRCLE);
        ticTacToe.setSquare(1, SquareEnum.CIRCLE);
        ticTacToe.setSquare(2, SquareEnum.CIRCLE);
        assertEquals("AI", ticTacToe.hasPlayerWon());
    }

    @Test
    public void testMiniMax() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(0, SquareEnum.CIRCLE);
        ticTacToe.setSquare(1, SquareEnum.CIRCLE);
        ticTacToe.setSquare(2, SquareEnum.CIRCLE);
        assertEquals(100, ticTacToe.miniMax(4, false));
        ticTacToe.setSquare(0, SquareEnum.EMPTY);
        ticTacToe.setSquare(1, SquareEnum.EMPTY);
        ticTacToe.setSquare(2, SquareEnum.EMPTY);

        ticTacToe.setSquare(0, SquareEnum.CROSS);
        ticTacToe.setSquare(1, SquareEnum.CROSS);
        ticTacToe.setSquare(2, SquareEnum.CROSS);
        assertEquals(-100, ticTacToe.miniMax(4, false));
        ticTacToe.setSquare(0, SquareEnum.EMPTY);
        ticTacToe.setSquare(1, SquareEnum.EMPTY);
        ticTacToe.setSquare(2, SquareEnum.EMPTY);


        ticTacToe.setSquare(0, SquareEnum.CROSS);
        ticTacToe.setSquare(1, SquareEnum.CROSS);
        assertEquals(-99, ticTacToe.miniMax(4, false));
    }
}