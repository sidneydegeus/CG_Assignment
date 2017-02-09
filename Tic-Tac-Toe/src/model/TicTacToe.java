package model;

import javafx.embed.swing.SwingFXUtils;
import javafx.fxml.FXMLLoader;
import javafx.scene.image.Image;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Rectangle;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
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
                BufferedImage bufferedImage;
                bufferedImage = ImageIO.read(new File("images/cross.png"));
                Image image = SwingFXUtils.toFXImage(bufferedImage, null);

                rectangle.setFill(new ImagePattern(image));
                turn = SquareEnum.CIRCLE;
            }
            if (turn == SquareEnum.CIRCLE) {
                Image img = new Image(FXMLLoader.load(getClass().getClassLoader().getResource("images/circle.png")).toString());
                rectangle.setFill(new ImagePattern(img));
                turn = SquareEnum.CROSS;
            }
        }

        System.out.println("clicked "  + index);
    }
}
