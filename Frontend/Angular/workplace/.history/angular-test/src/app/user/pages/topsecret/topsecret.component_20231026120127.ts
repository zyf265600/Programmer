import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-topsecret',
  templateUrl: './topsecret.component.html',
  styleUrls: ['./topsecret.component.css']
})
export class TopsecretComponent implements OnInit{
  private name: string  = '';

  constructor(private route: ActivatedRoute) {}
  
  ngOnInit() {
    this.name = this.route.snapshot.data['name'];
  }
}
