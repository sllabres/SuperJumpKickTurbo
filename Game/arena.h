
#pragma once

#include "includes.h"
#include "../Framework/Display/spritesheet.h"
#include "fighter.h"

#define SLOWMODE_DELAY_FRAMES		2
#define ROUND_TIME							20

class Arena : public Stage
{
	private:
		SpriteSheet* CollisionGraphics;
		Animation* CollisionAnimation;
		Vector2* CollisionsAt[2];

		ALLEGRO_FONT* fntTimer;
		int CountdownTimer;
		int CountdownTimerTicker;
		bool DisableTimer;

		int Player1Wins;
		int Player2Wins;
		ALLEGRO_BITMAP* Background;
		Vector2 Camera;

		int CamXMove;
		int CamYMove;

		int SlowMode;
		int SlowModeDelay;

		bool DebugReverse;

		long ClockRoundFrameCount[ROUND_TIME];

		void FixCameraPosition();
		void TickRoundClock();

		Fighter* GetPlayerWithControls( Fighter::FighterController Controller );

  public:
		bool DemoMode;
		long RoundFrameCount;

		Fighter* Player1;
		Fighter* Player2;

		int ArenaWidth;

		Arena();
		Arena( std::string LocationImage, Fighter* P1, Fighter* P2 );
		~Arena();

		void ResetArena();
		Fighter* GetOpponent(Fighter* Current);

		bool State_Load(long FrameCount);
		void AddCollisionAt( Vector2* Location );

    // Stage control
    virtual void Begin();
    virtual void Pause();
    virtual void Resume();
    virtual void Finish();
    virtual void EventOccurred(Event *e);
    virtual void Update();
    virtual void Render();
		virtual bool IsTransition();
};
