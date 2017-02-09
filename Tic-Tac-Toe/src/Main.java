/**
 * Created by jorda on 9-2-2017.
 */
import javafx.fxml.FXMLLoader;

import javafx.application.Application;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    private Stage window;
    private double width = 520;
    private double height = 480;

    @Override
    public void start(Stage primaryStage) throws Exception{
        this.window = primaryStage;
        Parent root = FXMLLoader.load(getClass().getResource("view/Main.fxml"));
        window.setTitle("Tic-Tac-Toe by Jordan Munk & Sidney de Geus");
        root.setId("pane");

        Scene scene = new Scene(root, width, height);
        scene.getStylesheets().addAll(this.getClass().getResource("css/style.css").toExternalForm());
        window.setScene(scene);
        window.centerOnScreen();
        window.show();
    }


    public static void main(String[] args) {
        launch(args);
    }

}