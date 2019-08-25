//  0. 이전 버전 내용
/*
		Ver 1.0 : OOP(객체지향) 단계별 프로젝트의 기본틀 구성
					- 메뉴출력
					- 계좌개설
					- 입금
					- 출금
					- 계좌조회

		Ver 1.1 : 분할 컴파일

		Ver 1.2 :
			1. 캡슐화, 정보은닉 적용
			2. 생성자, 소멸자 적용
			3. 객체 배열 적용

		Ver 1.2.1 : 복사생성자 적용

		Ver 1.2.2 :
			1. 컨트롤 클래스, 엔터티 클래스를 정의후 반영
			2. 원본 데이터의 변경의 방지을 위해서 const 키워드 반영.
			3. 클래스 정의부와 클래스 함수 몸체 구현부를 분리해서 프로그램 작성.

		Ver 1.2.3 :
			1. 클래스 이름: NormalAccount.
			   클래스 유형: 보통예금계좌 Entity 클래스

			2. 클래스 이름: HighCreditAccount.
			   클래스 유형: 신용신뢰계좌 Entity 클래스

			3. 신용등급
			 //enum {LEVEL_A=7, LEVEL_B=4, LEVEL_C=2}

			4. 계좌의 종류
			//enum {NORMAL=1, CREDIT=2}

			[ 기능 1. 계좌개설 ]
			- 보통예금계좌와 신용신뢰계좌 클래스를 만든다.
			- 보통예금계좌에는 아래와 같은 특성을 부여하도록 한다.
			  보통예금계좌 클래스는 이율정보를 등록할 수 있도록 한다.

			- 신용신뢰계좌에는 아래와 같은 특성을 부여하도록 한다.
			  고객의 신용등급을 A, B, C로 나누고 계좌개설시 이 정보를 등록한다.
			  A, B, C 등급별로 각각 기본이율에 7%, 4%, 2%의 이율을 추가로 제공한다.
			  계좌개설 과정에서 초기 입금되는 금액에 대해서는 이자를 계산하지 않는다.
			  계좌개설 후 별도의 입금과정을 거칠 때에만 이자가 발생하는 것으로 간주한다.
			  이자의 계산과정에서 발생하는 소수점 이하의 금액은 무시한다.

			[ 기능 2. 입금 ]
			[ 기능 3. 출금 ]
			[ 기능 4. 전체고객 잔액조회 ]

		Ver 1.3 : ver_01.2.3 파일 분할
			- Account 클래스의 선언과 정의
				Account.h, Account.cpp

			- NormalAccount 클래스의 선언과 정의
				 NormalAccount.h

			- HighCreditAccount 클래스의 선언과 정의
				 HighCreditAccount.h

			- AccountHandlr 클래스의 선언과 정의
				AccountHandlr.h, AccountHandlr.cpp

			- 공통헤더 및 상수선언들
				MiniBankingCommonDecl.h

			- Main 함수의 정의
				MiniBankingSystemMain.cpp

		Ver 1.3.1 : ver_01.2.3 파일 분할
			- 문자열 상수 static으로 변경
				static const char* DEPOSIT = "DEPOSIT";
				static const char* WITHDRAW = "WITHDRAW";

			- 그외 변경없음

		Ver 1.3.2 :
			1. Control class는 계좌 관리를 위해서 배열을 멤버로 선언되어 있다.
			   이 부분을 배열클래스로 대체하도록 한다.
			   배열클래스에서 계좌를 관리할 때, 계좌의 객체 포인터를 관리할 수 있도록 한다.

			2. 본인이 정의한 String class를 MiniBankingSystem에 활용할 수 있도록 적용한다.
			   각 Account class의 계좌주명을 String class로 대체할 수 있도록 반영한다.

		Ver 1.3.3 :
			1. 예외처리
				다음의 예외상황에 대한 처리를 C++의 예외처리 메커니즘 기반으로 적용.

				1.1. 계좌개설 이후, 예금된 금액보다 더 많은 금액의 출금을 요구하는 예외
				1.2. 계좌개설 이후, 입출금 진행 시 프로그램 사용자로부터 0보다 작은 값이
					 입력되는 예외 상황.
				1.3. 배열클래스의 저장공간이 더 이상 여유가 없어 저장할 수 없는 예외 상황.

			상기의 두 가지 예외 상황의 처리를 위해서 예외 상황별로 클래스를 정의하고,
			사용자에게는 잘못된 입력이 발생했음을 알리고 재 입력을 요구하는 방식으로
			예외상황이 처리되도록 구현.

			2. 파일 입출력
				2.1 프로그램 시작시 Data를 백업한 파일로부터 데이터를 읽어서 메모리에
					복구하는 기능.
				2.2 프로그램 종료시 Data의 백업을 위해서 메모리로부터 데이터를 읽어서
					파일에 백업하는 기능.
*/