// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <GameFramework/Actor.h>
#include <Kismet/GameplayStatics.h>
#include <GameFramework/SpringArmComponent.h>

/*Uncomment if using this version of the pawn to print out logs in-game screen
* using GEngine
*/
//#include <Engine/Engine.h>

// Sets default values
AMyPawn::AMyPawn()
{
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Sets this to first player to connect
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//Creates, and sets the components that are created with the pawn.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	//Attaches the sets to the root component
	SpringArmComp->SetupAttachment(RootComponent);
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName);

}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	//Gets first player controller, and makes sure mouse is always shown
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetShowMouseCursor(true);
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AMyPawn::MouseDown);
	InputComponent->BindAction("MouseClick", IE_Released, this, &AMyPawn::MouseUp);
}

void AMyPawn::MouseDown()
{
	//Writes to the Output Log in the editor
	UE_LOG(LogTemp, Warning, TEXT("Player Mouse Down"));

	//Writes to the screen
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("Player Mouse Up!"));
}

void AMyPawn::MouseUp()
{
	//Writes to the Output Log in the editor
	UE_LOG(LogTemp, Warning, TEXT("Player Mouse Up"));

	//Writes to the screen
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Player Mouse Down!"));
}

