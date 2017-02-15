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
        TicTacToe ticTacToe = new TicTacToe();
        assertEquals(9, ticTacToe.getPossibleMoves().size());
    }

    @Test
    public void testWin_012() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(0, SquareEnum.CIRCLE);
        ticTacToe.setSquare(1, SquareEnum.CIRCLE);
        ticTacToe.setSquare(2, SquareEnum.CIRCLE);
        assertEquals("AI", ticTacToe.hasPlayerWon());
    }

    @Test
    public void testWin_345() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(3, SquareEnum.CIRCLE);
        ticTacToe.setSquare(4, SquareEnum.CIRCLE);
        ticTacToe.setSquare(5, SquareEnum.CIRCLE);
        assertEquals("AI", ticTacToe.hasPlayerWon());
    }

    @Test
    public void testWin_678() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(6, SquareEnum.CIRCLE);
        ticTacToe.setSquare(7, SquareEnum.CIRCLE);
        ticTacToe.setSquare(8, SquareEnum.CIRCLE);
        assertEquals("AI", ticTacToe.hasPlayerWon());
    }

    @Test
    public void testWin_036() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(0, SquareEnum.CIRCLE);
        ticTacToe.setSquare(3, SquareEnum.CIRCLE);
        ticTacToe.setSquare(6, SquareEnum.CIRCLE);
        assertEquals("AI", ticTacToe.hasPlayerWon());
    }

    @Test
    public void testWin_048() throws Exception {
        TicTacToe ticTacToe = new TicTacToe();
        ticTacToe.setSquare(0, SquareEnum.CIRCLE);
        ticTacToe.setSquare(4, SquareEnum.CIRCLE);
        ticTacToe.setSquare(8, SquareEnum.CIRCLE);
        assertEquals("AI", ticTacToe.hasPlayerWon());
    }

    @Test
    public void testMiniMax() throws Exception {
/*        TicTacToe ticTacToe = new TicTacToe();
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
        ticTacToe.setSquare(2, SquareEnum.EMPTY);*/


        /*
        ticTacToe.setSquare(0, SquareEnum.CROSS);
        ticTacToe.setSquare(1, SquareEnum.CROSS);
        assertEquals(-99, ticTacToe.miniMax(4, false));*/
    }
}