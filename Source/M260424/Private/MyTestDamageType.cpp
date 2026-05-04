// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestDamageType.h"

UMyTestDamageType::UMyTestDamageType()
{
	// 이 데미지를 입었을 때 대상에게 가해질 물리적인 충격량(힘)
	DamageImpulse = 5000.0f;
	
	// 대상의 질량(무게)에 비례해서 충격량을 조절할지 여부
	// true: 무거운 캐릭터는 조금 밀리고, 가벼운 오브젝트는 멀리 날아간다
	// false: 무게에 상관없이 모두 동일한 힘으로 밀려난다
	bScaleMomentumByMass = true;

	// 이 데미지가 환경(월드)에 의해 발생했음
	// 외부 요인(트랩, 불덩이, 낙사 구역 같은 '맵 자체의 위험 요소'로부터 왔음을 알린다
		// 나중에 로그를 남기거나 사망 원인을 표시할 때 유용하게 쓰인다
	bCausedByWorld = true;
}
