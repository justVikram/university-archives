import {Component, OnInit} from '@angular/core';

@Component({
  selector: 'app-projects',
  templateUrl: './projects.component.html',
  styleUrls: ['./projects.component.css']
})
export class ProjectsComponent implements OnInit {

  registered_projects = [
    {
      title: 'YOU SAID THAT?',
      description: 'We present a method for generating a video of a talking face. The method takes as inputs: ' +
        '(i) still images of the target face, and (ii) an audio speech segment; and outputs a video of the target face ' +
        'lip synced with the audio. The method runs in real time and is applicable to faces and audio not seen at ' +
        'training time.',
      domain: 'Machine Learning',
      department: 'Computer Science'
    },
    {
      title: 'TOWARDS AUTOMATIC FACE-TO-FACE TRANSLATION',
      description: 'In light of the recent breakthroughs in automatic machine translation systems, we propose a novel ' +
        'approach that we term as "Face- to-Face Translation". As today’s digital communication becomes increasingly ' +
        'visual, we argue that there is a need for systems that can automatically translate a video of a person ' +
        'speaking in language A into a target language B.',
      domain: 'Deep Learning',
      department: 'Mechanical Engg.'
    },
    {
      title: 'A LIP SYNC EXPERT IS ALL YOU NEED',
      description: 'In this work, we investigate the problem of lip-syncing a talking face video of an arbitrary ' +
        'identity to match a target speech segment. Current works excel at producing accurate lip movements on a ' +
        'static image or videos of specific people seen during the training phase.',
      domain: 'Reinforcement Learning',
      department: 'Electrical Engg.'
    }
  ];

  constructor() {
  }

  ngOnInit(): void {
  }

}
