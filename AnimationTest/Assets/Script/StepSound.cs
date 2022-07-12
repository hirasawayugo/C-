using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StepSound : MonoBehaviour
{
  private AudioSource source;

  private void Awake()
  {
    source = GetComponents<AudioSource>()[0];
  }
  public void PlayFootstepSE()
  {
    source.Play();
  }
  public void StopFootstepSE()
  {
    source.Stop();
  }
}
