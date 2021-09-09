import {Component, OnInit} from '@angular/core';

@Component({
  selector: 'app-winners',
  templateUrl: './winners.component.html',
  styleUrls: ['./winners.component.css']
})

export class WinnersComponent implements OnInit {

  registered_projects = [
    {title: 'YOU SAID THAT?', domain: 'Machine Learning'},
    {title: 'TOWARDS AUTOMATIC FACE-TO-FACE TRANSLATION', domain: 'Deep Learning'},
    {title: 'A LIP SYNC EXPERT IS ALL YOU NEED', domain: 'Reinforcement Learning'},
    {title: 'SAMPLE', domain: 'Deep Learning'},
    {title: 'SAMPLE2', domain: 'Deep Learning'},
  ]

  winner = this.get_winner()

  constructor() {
  }

  ngOnInit(): void {
  }

  get_winner(): string {
    let candidates = []
    for (let i = 0; i < this.registered_projects.length; i++) {
      if (this.registered_projects[i].domain == 'Deep Learning')
        candidates.push(this.registered_projects[i].title);
    }
    return candidates[Math.floor(Math.random() * candidates.length)]
  }

}
