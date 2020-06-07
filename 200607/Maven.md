# 빌드란?

- 소스코드(java), 자원(.xml, .jpg, .properties) 를 JVM이나 WAS가 인식할 수 있는 구조로 패키징하는 과정 및 결과물



# 빌드 도구(Build tool)

- 프로젝트 생성, 테스트 빌드, 배포 등의 작업을 위한 전용 프로그램



# Maven

- Maven은 자바용 프로젝트 관리도구로 Apache Ant의 대안으로 만들어졌다
- Maven은 프로젝트의 전체적인 라이프 사이클을 관리하는 도구이다
- pom.xml 에 필요한 라이브러리를 정의해 놓으면 내가 필요한 라이브러리 뿐만 아니라 해당 라이브러리가 작동하는데 필요한 다른 라이브러리까지 네트워크를 통하여 자동으로 다운로드한다



# 플러그인(Plug-In)

- Maven에서 제공하는 모든 기능은 플러그인을 기반으로 동작한다

- 메이븐 자체는 기본적인 기능만 가지고 있고 대부분의 기능들은 플러그인을 통해 제공되어 있다

- goal은 명령을 의미한다

- 플러그인은 하나 이상의 goal의 집합체이다

  

# Life Cycle

- 메이븐은 프레임워크이기 때문에 동작 방삭이 정해져있고, 미리 정의되어진 빌드 순서가 있다. 이를 라이프사이클(Life Cycle)이라 한다
- Clean : 빌드 시 생성되었던 파일들을 삭제하는 단계
- Validate : 프로젝트가 올바른지 확인하고 필요한 모든 정보를 사용할 수 있는지 확인하는 단계
- Compile : 프로젝트의 소스코드를 컴파일 하는 단계
- Test : 유닛(단위) 테스트를 수행 하는 단계(테스트 실패시 빌드 실패로 처리, 스킵 가능)
- Pacakge : 실제 컴파일된 소스 코드와 리소스들을 jar, war 등등의 파일 등의 배포를 위한 패키지로 만드는 단계
- Verify : 통합 테스트 결과에 대한 검사를 실행하여 품질 기준을 충족하는지 확인하는 단계
- Install : 패키지를 로컬 저장소에 설치하는 단계
- Site : 프로젝트 문서와 사이트 작성, 생성하는 단계
- Deploy : 만들어진 package를 원격 저장소에 release 하는 단계



# Phase

- Life Cycle의 각 단계를 Phase 라고 한다.
- Phase는 의존관계를 가지고 있어 해당 Phase가 수행되려면 이전 단계의 Phase가 모두 수행되어야 한다



# Goal

- 최소한의 실행 단위 (task)

- 각각의 Phase에 연계된 Goal을 실행하는 과정을 Build라고 한다

- (예) mvn clean compiler:compile

  > "clean phase" 실행 > "compiler plugin의 compile goal" 실행

# 출처

- https://goddaehee.tistory.com/199 [갓대희의 작은공간]

- https://m.blog.naver.com/PostList.nhn?blogId=remagine [프로그래머잉]

