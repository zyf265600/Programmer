import { Component } from '@angular/core';

@Component({
  selector: 'app-data-bond',
  templateUrl: './data-bond.component.html',
  styleUrls: ['./data-bond.component.css']
})
export class data-bondComponent {
  username: string = ""
  change() {
    this.username = "hello Angular"
  }
}
