#include "Card.h"
#include "utilities.h"

Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;
    m_stats = stats; //TODO: need to unpack pointer? or is this ok because its a reference?
}

void battle(Player &player, int cardForce, int loot, int hpLoss){
    if (player.force>=cardForce){
        player.levelUp();
        player.addCoins(loot);
        printBattleResult(true);
        return;
    }
    else if (player.force<cardForce){
        player.damage(hpLoss);
        printBattleResult(false);
        return;
    }
}
void heal(Player &player, int cost, int heal){
    if (player.coins>=cost){
        player.coins-=cost;
        player.heal(heal);
        return;
    }
    else{
        return;
    }
}

void buff(Player &player, int cost, int buff){
    if (player.coins>=cost){
        player.coins-=cost;
        player.buff(buff);
        return;
    }
    else{
        return;
    }
}

void treasure(Player &player, int coins){
    player.addCoins(coins);
}

void Card::applyEncounter(Player &player) const {
    if (m_effect==CardType::Battle){
        battle(player,m_stats.force, m_stats.loot, m_stats.hpLossOnDefeat);
    }
    if (m_effect==CardType::Heal){
        heal(player,m_stats.cost, m_stats.heal);
    }
    if (m_effect==CardType::Buff){
        buff(player,m_stats.cost, m_stats.buff);
    }
    if (m_effect==CardType::Treasure){
        treasure(player,m_stats.loot);
    }
}

void Card::printInfo() const {
    if (m_effect==CardType::Battle){
        printBattleCardInfo(m_stats);
    }
    if (m_effect==CardType::Heal){
        printHealCardInfo(m_stats);
    }
    if (m_effect==CardType::Buff){
        printBuffCardInfo(m_stats);
    }
    if (m_effect==CardType::Treasure){
        printTreasureCardInfo(m_stats);
    }
}

