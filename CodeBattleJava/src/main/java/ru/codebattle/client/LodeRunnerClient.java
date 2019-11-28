package ru.codebattle.client;

import ru.codebattle.client.api.GameBoard;
import ru.codebattle.client.api.LoderunnerAction;
import ru.codebattle.client.api.LoderunnerBase;

import java.net.URISyntaxException;
import java.util.Random;
import java.util.function.Function;

public class LodeRunnerClient extends LoderunnerBase {

    private Function<GameBoard, LoderunnerAction> callback;

    public LodeRunnerClient(String serverAddress, String user, String code) throws URISyntaxException {
        super(serverAddress, user, code);
    }

    public void run(Function<GameBoard, LoderunnerAction> callback) {
        connect();
        this.callback = callback;
    }

    @Override
    protected String doMove(GameBoard gameBoard) {
        clearScreen();
        gameBoard.printBoard();
        Random random = new Random(System.currentTimeMillis());
        LoderunnerAction action = callback.apply(gameBoard);
        System.out.println(action.toString());
        return loderunnerActionToString(action);
    }

    public void clearScreen() {
        System.out.print("\033[H\033[2J");
        System.out.flush();
    }

    public void initiateExit() {
        System.exit(0);
    }
}
