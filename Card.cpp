#include "Card.h"

Card::Card(CardType type, const CardStats &stats) {
    m_effect = type;
    m_stats = stats;
}

void battle(Player &player, int cardForce, int loot, int hpLoss) {
    if (player.getAttackStrength() >= cardForce)
    {
        player.levelUp();
        player.addCoins(loot);
        printBattleResult(true);
    } else if (player.getAttackStrength() < cardForce)
    {
        player.damage(hpLoss);
        printBattleResult(false);
    }
}

void heal(Player &player, int cost, int heal) {
    if (player.pay(cost))
    {
        player.heal(heal);
    }
}

void buff(Player &player, int cost, int buff) {
    if (player.pay(cost))
    {
        player.buff(buff);
    }
}

void treasure(Player &player, int coins) {
    player.addCoins(coins);
}

void Card::applyEncounter(Player &player) const {
    if (m_effect == CardType::Battle)
    {
        battle(player, m_stats.force, m_stats.loot, m_stats.hpLossOnDefeat);
    }
    if (m_effect == CardType::Heal)
    {
        heal(player, m_stats.cost, m_stats.heal);
    }
    if (m_effect == CardType::Buff)
    {
        buff(player, m_stats.cost, m_stats.buff);
    }
    if (m_effect == CardType::Treasure)
    {
        treasure(player, m_stats.loot);
    }
}

void Card::printInfo() const {
    if (m_effect == CardType::Battle)
    {
        printBattleCardInfo(m_stats);
    }
    if (m_effect == CardType::Heal)
    {
        printHealCardInfo(m_stats);
    }
    if (m_effect == CardType::Buff)
    {
        printBuffCardInfo(m_stats);
    }
    if (m_effect == CardType::Treasure)
    {
        printTreasureCardInfo(m_stats);
    }
}

