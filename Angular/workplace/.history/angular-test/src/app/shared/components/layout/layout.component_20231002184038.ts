import { Component, ElementRef, ViewChild, AfterViewInit, QueryList, ViewChildren } from "@angular/core"

@Component({
  selector: 'app-layout',
  templateUrl: './layout.component.html',
  styleUrls: ['./layout.component.css']
})
export class LayoutComponent {
  username: string = ""
  change() {
    this.username = "hello Angular"
  }
}
