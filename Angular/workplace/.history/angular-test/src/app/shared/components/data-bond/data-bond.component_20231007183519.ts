import { Component } from '@angular/core';

@Component({
  selector: 'app-layout',
  templateUrl: './data-bond.component.html',
  styleUrls: ['./data-bond.component.css']
})
export class LayoutComponent {
  username: string = ""
  change() {
    this.username = "hello Angular"
  }
}
