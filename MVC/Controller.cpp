//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"

BattleShip::Controller::Controller():model(){
    view = std::make_unique<StandardView>();
}

void BattleShip::Controller::setupGame(const BattleShip::GameAttributes& game, int seed){
    BattleShip::AiPlayer::seed_random_number_generator(seed);
    PlayerConfiguration playConfig = view->getPlayerConfiguration();
    model.loadGameConfiguration(game);

    if (playConfig.numAiPlayers == 0){
        model.addPlayer<HumanPlayer>(*view);
        model.addPlayer<HumanPlayer>(*view);
    } else if (playConfig.numAiPlayers == 1){
        model.addPlayer<HumanPlayer>(*view);
        int choice = view->getAiChoice();

        if (choice == 1){
            model.addPlayer<CheatingAI>(*view);
        } else if (choice == 2){
            model.addPlayer<RandomAI>(*view);
        } else if (choice == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }


    } else if (playConfig.numAiPlayers == 2){
        int choice = view->getAiChoice();

        if (choice == 1){
            model.addPlayer<CheatingAI>(*view);
        } else if (choice == 2){
            model.addPlayer<RandomAI>(*view);
        } else if (choice == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }

        choice = view->getAiChoice();

        if (choice == 1){
            model.addPlayer<CheatingAI>(*view);
        } else if (choice == 2){
            model.addPlayer<RandomAI>(*view);
        } else if (choice == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }

    }
    model.getAttackingPlayer().setOpponent(model.getDefendingPlayer());
    model.getDefendingPlayer().setOpponent(model.getAttackingPlayer());
    hasBeenSetUp = true;
}
void BattleShip::Controller::setupGame(const BattleShip::GameAttributes& game){
    PlayerConfiguration playConfig = view->getPlayerConfiguration();
    model.loadGameConfiguration(game);

    if (playConfig.numAiPlayers == 0){
        model.addPlayer<HumanPlayer>(*view);
        model.addPlayer<HumanPlayer>(*view);
    } else if (playConfig.numAiPlayers == 1){
        model.addPlayer<HumanPlayer>(*view);
        int choice = view->getAiChoice();

        if (choice == 1){
            model.addPlayer<CheatingAI>(*view);
        } else if (choice == 2){
            model.addPlayer<RandomAI>(*view);
        } else if (choice == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }

    } else if (playConfig.numAiPlayers == 2){
        int choice = view->getAiChoice();

        if (choice == 1){
            model.addPlayer<CheatingAI>(*view);
        } else if (choice == 2){
            model.addPlayer<RandomAI>(*view);
        } else if (choice == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }

        choice = view->getAiChoice();

        if (choice == 1){
            model.addPlayer<CheatingAI>(*view);
        } else if (choice == 2){
            model.addPlayer<RandomAI>(*view);
        } else if (choice == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }

    }

    model.getAttackingPlayer().setOpponent(model.getDefendingPlayer());
    model.getDefendingPlayer().setOpponent(model.getAttackingPlayer());
    hasBeenSetUp = true;
}
void BattleShip::Controller::playGame(){
    while (!model.isGameOver()){
        auto move = model.getNextMove();
        move->enact(model, *view);
        model.changeTurn();
    }
}
