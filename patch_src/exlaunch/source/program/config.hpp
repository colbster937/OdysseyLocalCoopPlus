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
};

const Settings& Get();
void Reload();

unsigned RespawnDelayFrames();
unsigned BubbleHoldFrames();
unsigned BubbleCooldownFrames();

}  // namespace ocoop::config
