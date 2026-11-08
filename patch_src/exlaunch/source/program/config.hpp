#pragma once

namespace ocoop::config {

struct Settings {
    float cameraBaseZoom;
    float cameraMaxZoom;
    float cameraSeparationStart;
    float cameraSeparationFull;
    float cameraLerp;

    char p2Body[64];
    char p2Cap[64];

    float respawnDelaySeconds;

    float bubbleDistance;
    float bubbleHoldSeconds;
    float bubbleCooldownSeconds;
    bool bubbleWaterCountsAsGround;

    bool coinRaceEnabled;
    int coinRaceTarget;
    float coinRaceHudX;
    float coinRaceHudY;
    float coinRaceHudSpacing;

    bool moonRaceEnabled;
    int moonRaceTarget;
    float competitionHudX;
    float competitionHudY;

    /* Sideways distance (game units) P2 spawns from P1, along P1's local X axis.
     * 0 = spawn on top of P1 (previous behavior); negative = other side. */
    float p2SpawnOffset;

    /* Total players in co-op mode (2..kMaxPlayers). Clamped at spawn time to
     * the number of connected controllers. */
    int playerCount;
    char p3Body[64];
    char p3Cap[64];
    char p4Body[64];
    char p4Cap[64];

    /* Extra players exit the stage-start door/pipe one after another. */
    bool staggeredEntrance;
};

/* The game's PlayerHolder has 4 slots in both 1.0.0 and 1.3.0
 * (StageScene::init passes 4 to initLiveActorKitWithGraphics). */
constexpr int kMaxPlayers = 4;

const Settings& Get();
void Reload();

/* Override the config-file default until the game exits; survives Reload(). */
void SetSessionPlayerCount(int count);

/* Costume archive names for holder slot 1..3 (P2..P4). Empty = inherit P1. */
const char* PlayerBody(int slot);
const char* PlayerCap(int slot);

unsigned RespawnDelayFrames();
unsigned BubbleHoldFrames();
unsigned BubbleCooldownFrames();

}  // namespace ocoop::config
