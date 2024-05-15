import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ComponentHelloworldComponent } from './component-helloworld.component';

describe('ComponentHelloworldComponent', () => {
  let component: ComponentHelloworldComponent;
  let fixture: ComponentFixture<ComponentHelloworldComponent>;

  beforeEach(() => {
    TestBed.configureTestingModule({
      declarations: [ComponentHelloworldComponent]
    });
    fixture = TestBed.createComponent(ComponentHelloworldComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
