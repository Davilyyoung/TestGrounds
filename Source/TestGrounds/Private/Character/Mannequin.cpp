// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Mannequin.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Weapon/Gun.h"

// Sets default values
AMannequin::AMannequin()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create a CameraComponent	
	FirstPersonCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCameraComp"));
	FirstPersonCameraComp->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComp->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComp->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1PComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh1PComp"));
	Mesh1PComp->SetOnlyOwnerSee(true);
	Mesh1PComp->SetupAttachment(FirstPersonCameraComp);
	Mesh1PComp->bCastDynamicShadow = false;
	Mesh1PComp->CastShadow = false;
	Mesh1PComp->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1PComp->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
	
}

// Called when the game starts or when spawned
void AMannequin::BeginPlay()
{
	Super::BeginPlay();

	if (!ensure(GunBlueprint))
	{
		UE_LOG(LogTemp,Warning,TEXT("Gun blueprint missing."))
		return;
	}

	Gun = GetWorld()->SpawnActor<AGun>(GunBlueprint);
	Gun->AttachToComponent(Mesh1PComp,FAttachmentTransformRules(EAttachmentRule::SnapToTarget,true),TEXT("GripPoint"));//Attach gun mesh comp
	Gun->AnimInstance = Mesh1PComp->GetAnimInstance();

	if (InputComponent != NULL)
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &AMannequin::PullTrigger);
	}
	
}

// Called every frame
void AMannequin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMannequin::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMannequin::PullTrigger()
{
	Gun->OnFire();
}

