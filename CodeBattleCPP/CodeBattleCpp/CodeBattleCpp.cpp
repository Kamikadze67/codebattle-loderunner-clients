#include <iostream>
#include <random>

#include "GameClientLodeRunner.h"

	/*
		���� ��� ������ ��������� ������ ���� 
		The Windows SDK version 10.0.16299.0 was not found...
		������ ���������:
			1)������ ������� ���� �� CodeBattleCpp � ��� �� properties.
			2)������� Configuration Properties->General
			3)������� Windows SDK Version � ����� ��������� � ���������� ������
			4)�������� Apply
			5)��������� ���� ����� � CodeBattleCppLibrary
	*/


void main()
{
	srand(time(0));
	/*
	 ����� ����������� ��� �������� �� �������� � ������ � ������� �������.
	 URL ����� �������� �����: http://localhost:8888/codenjoy-contest/board/player/cg601yim3186cotnftue?code=8887669793631271133&gameName=loderunner
	 �� url ����:
	 ����� ������� = localhost:8888
	 id ������������ = cg601yim3186cotnftue
	 ��� ������������ = 8887669793631271133
	*/
	std::string url = "localhost:8888";
	std::string userId = "<player-id>";
	std::string userCode = "<code>";
	GameClientLodeRunner *gcb = new GameClientLodeRunner(url, userId, userCode);
	gcb->Run([&]()
	{
			GameBoard* gb = gcb->get_GameBoard();
			std::list<BoardPoint> gold = gb->getGoldPositions();

			bool done = false;
			switch (rand() % 5)
			{
			case 0: gcb->LoderunnerAction(LoderunnerAction::GO_UP); done = true; break;
			case 1: gcb->LoderunnerAction(LoderunnerAction::GO_DOWN); done = true; break;
			case 2: gcb->LoderunnerAction(LoderunnerAction::GO_LEFT); done = true; break;
			case 3: gcb->LoderunnerAction(LoderunnerAction::GO_RIGHT); done = true; break;
			case 4: gcb->LoderunnerAction(LoderunnerAction::DRILL); done = true; break;
			}
			if (!done) {
				gcb->LoderunnerAction(LoderunnerAction::DO_NOTHING);
			}
	});

	getchar();
}
