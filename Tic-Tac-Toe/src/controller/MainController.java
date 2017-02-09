package controller;

/**
 * Created by jorda on 1-2-2017.
 */

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Group;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.paint.ImagePattern;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;
import jdk.nashorn.internal.runtime.arrays.NumericElements;
import model.TicTacToe;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class MainController implements Initializable{

/*    @FXML
    private TilePane tilePane;*/

    @FXML
    private GridPane gridPane;
    private GraphicsContext gc ;
    private TicTacToe ticTacToe;

    private static final double ELEMENT_SIZE = 100;
    private static final double GAP = ELEMENT_SIZE / 10;

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        ticTacToe = new TicTacToe();
        for (int i = 0 ; i < 3 ; i++) {
            ColumnConstraints colConstraints = new ColumnConstraints();
            colConstraints.setHgrow(Priority.SOMETIMES);
            gridPane.getColumnConstraints().add(colConstraints);
        }

        for (int i = 0 ; i < 3 ; i++) {
            RowConstraints rowConstraints = new RowConstraints();
            rowConstraints.setVgrow(Priority.SOMETIMES);
            gridPane.getRowConstraints().add(rowConstraints);
        }

        drawField();
        //gc = canvas.getGraphicsContext2D();
    }

    private void drawField() {
        for (int i = 0 ; i < 3 ; i++) {
            for (int j = 0; j < 3; j++) {
                Rectangle rectangle = new Rectangle(100, 100);
                rectangle.setStroke(Color.ORANGE);
                int row = i;
                int column = j;
                rectangle.setOnMouseClicked(e -> {
                    try {
                        ticTacToe.squareClicked(rectangle, row, column);
                    } catch (IOException e1) {
                        e1.printStackTrace();
                    }
                });
                gridPane.add(rectangle, j, i);
            }
        }
    }
}